#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<ll> burger(51),pattys(51);
ll dfs(int n, ll x, int depth){
    if(depth==1){
        ll p = 0;
        if(x==1) p=0;
        else if(1<x&&x<5) p=x-1;
        else p=3;
        return p;
    }
    //b=第depth層にあるdepth-1バーガーの層数
    ll b=burger[depth-1];
    ll ans = 0;
    if(x==1){
        ans = 0;
    }else if(x<=1+b){
        ans += dfs(n,x-1,depth-1);
    }else if(x==2+b){
        ans += pattys[depth-1]+1;
    }else if(x<=2+2*b){
        ans += pattys[depth-1]+1;
        ans += dfs(n,x-2-b,depth-1);
    }else if(x==burger[depth]){
        ans += pattys[depth];
    }
    return ans;
}
int main(){
    int n;
    ll x;
    cin>>n>>x;
    burger[0]=1;
    pattys[0]=1;
    for(int i=0; i<50; i++){
        burger[i+1]=burger[i]*2+3;
        pattys[i+1]=pattys[i]*2+1;
    }
    cout<<dfs(n,x,n)<<endl;
}