#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<initializer_list>
class stra{

    public:
    typedef std::vector<std::string>::size_type size_type;
    stra();
    
    stra(const std::initializer_list<std::string>& il);
    stra(const stra& s);
    stra& operator=(const stra& s);

    size_type size()const{return data->size();}
    bool empty()const{return data->empty();}
    void push_back(const std::string& s){
        data->push_back(s);
    }
    void pop_back();
    std::string& front();
    std::string& back();
    void printcount(){
        std::cout<<"count:"<<data.use_count()<<std::endl;
    }




    private:
    std::shared_ptr<std::vector<std::string>>data;
    void check(size_type i,const std::string&msg)const;


};


stra::stra(){
    data=std::make_shared<std::vector<std::string>>();
}
stra::stra(const std::initializer_list<std::string>& il){
    data=std::make_shared<std::vector<std::string>>(il);
}
stra::stra(const stra& s){
    data=s.data;
}
stra& stra::operator=(const stra& s){
    if(this!=&s){
        this->data=s.data;
    }
    return *this;
}
void stra::check(size_type i,const std::string&msg)const{
    if(i>=data->size()){
        throw std::out_of_range(msg);
    }
}
std::string& stra::front(){
    check(0,"front on empty stra");
    return data->front();
}
std::string& stra::back(){
    check(0,"back on empty stra");
    return data->back();
}
void stra::pop_back(){
    check(0,"pop_back on empty stra");
    data->pop_back();
}

void test_stra(){
    stra s1={"hello","jiang","you","are","handsome"};
    std::cout<<"s2赋值前: "<<std::endl;
    s1.printcount();
    stra s2=s1;
    std::cout<<"s2赋值后: "<<std::endl;
    s1.printcount();
    std::cout<<s1.back()<<std::endl;
    s2.pop_back();
    std::cout<<"s2.back():"<<s2.back()<<std::endl;
}
int main(){
    test_stra();
    return 0;
}