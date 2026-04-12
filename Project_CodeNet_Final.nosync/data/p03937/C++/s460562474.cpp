#include<bits/stdc++.h>
#define endl enjoy_codeforces
using lint=long long;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    int h,w;std::cin>>h>>w;
    std::vector<int>ckd(h+w-1);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;std::cin>>c;
            if(c=='#'&&std::exchange(ckd.at(i+j),true)){
                std::cout<<"Impossible"<<'\n';
                return 0;
            }
        }
    }
    std::cout<<"Possible"<<'\n';
}
