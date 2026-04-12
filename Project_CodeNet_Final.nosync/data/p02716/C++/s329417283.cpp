#include<bits/stdc++.h>
#define ALL(v) std::begin(v),std::end(v)
using lint=long long;
using ld=long double;
template<class T>using numr=std::numeric_limits<T>;
void cmx(lint&x,lint y){if(x<y)x=y;}
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint inf=numr<lint>::max();
    lint n;std::cin>>n;
    std::vector<lint>a(n+4);
    for(lint i=2;i<n+2;i++){
        std::cin>>a.at(i);
    }
    n+=4;
    std::vector<std::array<lint,3>>dp(n,std::array<lint,3>{-inf,-inf,-inf});
    dp.at(0).at(0)=0;
    for(lint i=0;i<n;i++){
        for(lint j=0;j<3;j++){
            if(dp.at(i).at(j)==-inf)continue;
            for(lint k=0;j+k<3&&i+2+k<n;k++){
                cmx(dp.at(i+2+k).at(j+k),dp.at(i).at(j)+a.at(i+2+k));
            }
        }
    }
    std::cout<<dp.at(n-1).at(1+n%2)<<'\n';
}
