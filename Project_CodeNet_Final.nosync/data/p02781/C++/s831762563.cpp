#include<bits/stdc++.h>
using lint=long long;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    std::string s;std::cin>>s;
    lint k;std::cin>>k;
    std::vector<std::vector<lint>>dp(k+1,std::vector<lint>(2));
    dp.at(0).at(0)=1;
    for(char c:s){
        lint x=c-'0';
        std::vector<std::vector<lint>>swp(k+1,std::vector<lint>(2));
        for(lint i=0;i<=k;i++){
            if(x==0){
                swp.at(i).at(0)+=dp.at(i).at(0);//0
                swp.at(i).at(1)+=dp.at(i).at(1);//0
                if(i<k)swp.at(i+1).at(1)+=dp.at(i).at(1)*9;//1,..,9
            }else{
                swp.at(i).at(1)+=dp.at(i).at(0);//0
                if(i<k)swp.at(i+1).at(1)+=(x-1)*dp.at(i).at(0);//1..x-1
                if(i<k)swp.at(i+1).at(0)+=dp.at(i).at(0);//x
                swp.at(i).at(1)+=dp.at(i).at(1);//0
                if(i<k)swp.at(i+1).at(1)+=dp.at(i).at(1)*9;//1,..,9
            }
        }
        swp.swap(dp);
    }
    std::cout<<dp.at(k).at(0)+dp.at(k).at(1)<<'\n';
}
