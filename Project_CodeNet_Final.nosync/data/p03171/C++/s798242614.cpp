//
//  main.cpp
//  DPL

#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
vector<ll>as(3005);
vector<vector<bool>>flag(3005,vector<bool>(3005,false));
vector<vector<ll>>dp(3005,vector<ll>(3005));
ll f(int i,int j){
   if(flag.at(i).at(j)) return dp.at(i).at(j);
    if(i==j){
        return dp.at(i).at(j)=as.at(i);
    }
    flag.at(i).at(j)=true;
    return dp.at(i).at(j)=max(as.at(i)-f(i+1,j),as.at(j)-f(i,j-1));
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    rep(i,n) {
        cin>>as.at(i);
    }
    rep(i,n){
        for(int j=i;j<n;j++){
            dp.at(i).at(j)=f(i,j);
        }
    }
    cout<<dp.at(0).at(n-1)<<endl;
    return 0;
}
