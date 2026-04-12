#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

vector<ll>p(60,1),a(60,1);

ll f(ll n,ll x){
    if(n==0){
        return (x<=0?0:1);
    }
    if(x==1){
        return 0;
    }
    else if(x<=a[n-1]+1){
        return f(n-1,x-1);
    }
    else if(x==a[n-1]+2)return p[n-1]+1;
    else if(x<=2*a[n-1]+2){
        return p[n-1]+1+f(n-1,x-2-a[n-1]);
    }
    else if(x==2*a[n-1]+3){
        return 2*p[n-1]+1;
    }
}

int main(){
    for (int i = 0; i < 60; ++i) {
        p[i+1]=2*p[i]+1;
        a[i+1]=2*a[i]+3;
    }
    ll n,x;cin >>n>>x;
    cout <<f(n,x)<<endl;
    return 0;
}