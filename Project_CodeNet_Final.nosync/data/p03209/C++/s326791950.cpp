#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> a;
vector<ll> p;

ll rec(ll n,ll x){
    if(n==0){
        if(x<=0) return 0;
        else     return 1;
    }

    if(x==1) return 0;
    else if(x<2+a[n-1]) return rec(n-1,x-1);
    else if(x==2+a[n-1]) return p[n-1]+1;
    else if(x<a[n]) return rec(n-1,x-a[n-1]-2)+p[n-1]+1;
    else return p[n];
}

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin >> n >> x;
    a.assign(n+1,(ll)1);
    p.assign(n+1,(ll)1);
    for(int i = 0; i < n; i++) {
        a[i+1]=a[i]*2+3;
        p[i+1]=p[i]*2+1;
    }
    ll ans=rec(n,x);
    cout << ans << "\n";
    return 0;
}