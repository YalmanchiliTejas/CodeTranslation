#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll a(int n){
    return (1LL<<(n+1))-1;
}
ll b(int n){
    return (1LL<<(n+2))-3;
}

ll dfs(int n,ll x){
    if(n==0 && x==1) return 1;
    if(x==0) return 0;
    if(x==1) return 0;
    x--;
    if(x<=b(n-1)) return dfs(n-1,x);
    x-=b(n-1);
    ll res=a(n-1);
    if(x==0) return res;
    x--;
    res++;
    if(x<=b(n-1)) return res+dfs(n-1,x);
    return res+a(n-1);
}

int main(){
    int n;
    ll x;
    cin>>n>>x;
    cout<<dfs(n,x)<<endl;
    return 0;
}