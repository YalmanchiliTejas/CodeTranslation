#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

ll solve(int n, ll x){
    if(n==0)return 1;
    ll len=(1LL<<(n+1))-3;
    ll num=(1LL<<n)-1;
    if(x==1)return 0;
    else if(x<=len+1)return solve(n-1,x-1);
    else if(x==len+2)return num+1;
    else if(x<=(len+1)*2)return num+1+solve(n-1,x-len-2);
    else return num*2+1;
}

int main(){
    int n; ll x;
    cin>>n>>x;
    cout<<solve(n,x)<<endl;
    return 0;
}