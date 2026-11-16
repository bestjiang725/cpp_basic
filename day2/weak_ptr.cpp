#include<iostream>
#include<memory>
#include<vector>

void test1(){
    std::shared_ptr<int>p1(new int(725));
    std::weak_ptr<int>p2(p1);
    //弱引用不会增加引用计数
    std::cout<<"p1.use_count()="<<p1.use_count()<<std::endl;

}
std::weak_ptr<int> clone(int a){
    auto p=std::make_shared<int>(a);
    return std::weak_ptr<int>(p);
}
void test2(){ 
    auto p2=clone(725);
    if(p2.expired()){
        std::cout<<"p2 is expired"<<std::endl;

    }
    else{
        std::cout<<"p2 is not expired"<<std::endl;
        std::cout<<*(p2.lock())<<std::endl;
    }
}

int main(){
    test1();
    //因为局部变量随函数结束而销毁，所以p2是一个悬空指针
    test2();
    

    
    return 0;
}