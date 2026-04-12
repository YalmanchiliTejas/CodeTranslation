#include<bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll inf = 1<<30;
vector<ll> a(55);
vector<ll> p(55);
ll f(ll n,ll x){
    if(n<=0) return (x<=0)?0:1;
    
    if(x <= a[n-1] + 1){
        return f(n-1,x-1);
    }else{
        return p[n-1] + 1 + f(n-1,x-2-a[n-1]);
    }
    
}
int main(){
    int n;
    ll x;
    cin>>n>>x;
    a[0] = 1;
    p[0] = 1;
    for(int i=0;i<n;++i){
       a[i+1] = 2*a[i]+3;
       p[i+1] = 2*p[i]+1;
    }
    cout << f(n,x) << endl;
    return 0;
}
