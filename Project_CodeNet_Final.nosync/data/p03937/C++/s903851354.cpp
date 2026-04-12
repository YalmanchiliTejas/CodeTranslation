#include<bits/stdc++.h>
using lint=long long;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint h,w;std::cin>>h>>w;
    std::vector<lint>ckd(h+w-1);
    for(lint i=0;i<h;i++){
        for(lint j=0;j<w;j++){
            char c;std::cin>>c;
            if(c=='#'){
                if(std::exchange(ckd.at(i+j),true)){
                    std::cout<<"Impossible"<<'\n';
                    return 0;
                }
            }
        }
    }
    std::cout<<"Possible"<<'\n';
}
