#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

vector<ll>a(60,1);
vector<ll>p(60,1);
ll f(ll x,ll level){
    if(level==0)return (x<=0?0:1);
    if(x==1)return 0;
    else if(x<=a[level-1]+1)return f(x-1,level-1);
    else if(x==a[level-1]+2)return p[level-1]+1;
    else if(x<=2*a[level-1]+2)return p[level-1]+1+f(x-a[level-1]-2,level-1);
    else return p[level-1]*2+1;
}

int main(){
    ll n;cin >>n;
    for (int i = 0; i <60 ; ++i) {
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }
    ll x;cin>>x;
    ll ans=f(x,n);
    cout <<ans <<endl;
    return 0;
}