#include <thread>
#include <iostream>
void sample(int x){
    std::cout<<"Thread id: "<<std::this_thread::get_id()<<std::endl;
    std::cout<<"Value of x is: "<<x<<std::endl;
}
int main(){
    //threads need a callable,also pass arguments to the callable
    std::thread t1(sample,123);
    std::thread t2(sample,456);
    t1.join();
    t2.join();

    /*
        above behaviour is not predictable every time.
        thread can get prempted before completion
        join() can help synchronize work flow
    */
   std::cout<<std::thread::hardware_concurrency<<std::endl;
}