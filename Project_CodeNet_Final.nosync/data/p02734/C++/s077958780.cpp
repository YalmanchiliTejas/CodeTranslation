#include<bits/stdc++.h>
using lint=long long;
lint mod=998'244'353;
void add_assign(lint&x,lint y){x+=y;if(mod<=x)x-=mod;}
int main(){
    lint n,S;std::cin>>n>>S;
    std::vector<lint>dp(S+1);
    lint ans=0;
    for(lint i=0;i<n;i++){
        lint x;std::cin>>x;
        for(lint j=S;j-x>=0;j--){
            add_assign(dp.at(j),dp.at(j-x));
        }
        if(x<=S)add_assign(dp.at(x),i+1);
        add_assign(ans,dp.at(S));
    }
    std::cout<<ans<<'\n';
}
