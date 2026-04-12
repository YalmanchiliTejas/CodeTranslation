#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll a,b,c;cin >>a>>b>>c;
    ll x,y;cin >>x>>y;
    ll mint=min(x,y);
    ll ans=0;
    if((a+b)>2*c){
        ans+=2*c*mint;
        x-=mint;
        y-=mint;
    }
    else {
        ans+=(a+b)*mint;
        x-=mint;
        y-=mint;
    }
    if(a>2*c){
        ans+=x*2*c;
    }
    else ans+=x*a;
    if(b>2*c){
        ans+=y*2*c;
    }
    else ans+=b*y;
    cout <<ans <<endl;
    return 0;
}