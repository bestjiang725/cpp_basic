#include<iostream>
#include<memory>
#include<vector>
void use_unique_ptr(){ 
    std::unique_ptr<std::string>p1(new std::string("hello jiang"));
    std::cout<<*p1<<std::endl;
    std::unique_ptr<std::string>p2(std::move(p1));
    std::cout<<*p2<<std::endl;
    std::cout<<p1.get()<<std::endl;
    std::unique_ptr<std::string>p3(new std::string("hello world"));
    p1.reset(p3.release());
    std::cout<<*p1<<std::endl;

}
//虽然说unique_ptr不能拷贝，但有个例外，能拷贝或者复制一个将要销毁的对象

std::unique_ptr<int> cop(int a){
    return std::unique_ptr<int>(new int(a));
}
void use2(){
    int a=1024;
    std::unique_ptr<int>p=cop(a);
    std::cout<<*p<<std::endl;

}

//unique_ptr删除器
void unique_deleter(int *p){
    std::cout<<"unique_deleter"<<std::endl;
    std::cout<<*p<<std::endl;
    delete p;
}

void use3(){
    std::unique_ptr<int,decltype(unique_deleter)*>p(new int(104),unique_deleter);

}

int main(){
    use_unique_ptr();
    use2();
    use3();

    
    return 0;
}