#include <iostream>
#include <algorithm>
#include <vector>
#include<deque>
 
int main()
{
    using Int=long long;
    int n;
    std::vector<Int> a={};
    std::cin>>n;
    Int t;
    for(;std::cin>>t;){
        a.push_back(t);
    }
    
    std::deque<Int> deq={};
    
    for(auto x: a){
        auto it = std::lower_bound(deq.begin(),deq.end(),x);
        if(it == deq.begin()){
            deq.push_front(x);
        }else{
            *(it-1)=x;
        }
    }
   
    std::cout<<deq.size();
}