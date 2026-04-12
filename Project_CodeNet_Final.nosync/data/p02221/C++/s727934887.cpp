#include<bits/stdc++.h>
using lint=long long;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint n;std::cin>>n;
    lint N=1;
    for(lint i=0;i<n;i++)N<<=1;
    std::vector<lint>a;
    lint g=N-1;
    {
        std::string s;std::cin>>s;
        a.resize(2*g+1);
        a.at(g)=-1;
        for(lint i=1;i<=g;i++){
            a.at(g+i)=s.at(i-1)=='1';
            a.at(g-i)=!a.at(g+i);
        }
    }
    std::vector<std::vector<lint>>dp(n+1,std::vector<lint>(2*N,-1));
    for(lint i=0;i<N;i++){
        lint x;std::cin>>x;
        dp.at(0).at(i)=dp.at(0).at(N+i)=x;
    }
    for(lint i=0;i<n;i++){
        lint I=1ll<<i;
        for(lint j=0;j<=2*N-2*I;j++){
            lint x=dp.at(i).at(j);
            lint y=dp.at(i).at(j+I);
            dp.at(i+1).at(j)=a.at(g+y-x)?y:x;
        }
    }
    for(lint i=0;i<N;i++){
        std::cout<<dp.at(n).at(i)<<'\n';
    }
}

