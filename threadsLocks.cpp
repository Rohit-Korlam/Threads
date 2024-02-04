#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <unordered_map>
std::mutex mtx;
/*
https://stackoverflow.com/questions/4989451/mutex-example-tutorial
*/
std::unordered_map<int32_t,std::string> store;

void savepage(int id,std::string s){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "content";
    mtx.lock();
    store.insert({id,result+"->"+s});
    mtx.unlock();
}
void printContents(){
    for(auto it=store.begin();it!=store.end();it++){
        std::cout<<"Key: "<<it->first<<" Value: "<<it->second<<std::endl;
    }
}
int main()
{
    std::thread t1(savepage,1,"https://first.com");
    std::thread t2(savepage,2,"https://second.com");
    t1.join();
    printContents();
    t2.join();
}