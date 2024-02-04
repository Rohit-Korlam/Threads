#include <thread>
#include <iostream>
int number;
void for_loop(int x){
    for(int i=0;i<10;i++){
        std::cout<<"id is: "<<x<<std::endl;
        number +=1; 
    }
}
int main(){
    std::thread t1(for_loop,2);
    std::thread t2(for_loop,3);
    t2.join();
    std::cout<<number<<std::endl;
    t1.join();
    std::cout<<number<<std::endl;
}