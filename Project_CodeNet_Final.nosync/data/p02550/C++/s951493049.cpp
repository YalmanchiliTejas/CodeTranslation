// This file is a "Hello, world!" in C++ language by Clang for wandbox.
#include <iostream>
#include <vector>
#include<numeric>

int main()
{
    std::uint64_t n,x,m;
    std::cin>>n>>x>>m;
    std::vector<uint64_t> mini = {x};
    uint64_t subindex=0;
    std::vector<uint64_t> memo(m, INT64_MAX);
    memo[x]=0;
    for(uint64_t i=1;i<n;++i){
        auto x = mini[i-1];
        auto x2 = x*x%m;
        if(memo[x2]!=INT64_MAX){
            subindex = memo[x2];
            break;
        }
        memo[x2]=i;
        mini.push_back(x2);
    }
    
    auto len = mini.size() - subindex;
    uint64_t zero = 0;
    auto t0 = std::accumulate(mini.begin(),mini.begin()+subindex,zero) ;
    auto t1 = std::accumulate(mini.begin()+subindex, mini.end(),zero) * ((n-subindex)/len);
    auto t2 = std::accumulate(mini.begin()+subindex, mini.begin() + subindex + (n-subindex)%len,zero);
    std::cout<<t0+t1+t2;
    
}