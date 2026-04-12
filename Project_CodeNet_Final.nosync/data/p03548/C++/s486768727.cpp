#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define V vector<ll>
using namespace std;
using ll = long long;

int main(){
    ll x,y,z;
    cin>>x>>y>>z;
    ll ans=1;
    ans+=(x-y-2*z)/(y+z);
    cout<<ans<<"\n";
}