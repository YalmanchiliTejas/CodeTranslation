//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (ll i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (ll i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x,m;cin>>n>>x>>m;
    vector<ll> a(m);
    rep(i,0,m){
        a[i] = i*i%m;
    }
    vector<ll> b(m+100),c;
    ll ans = 0;
    ll j = 0;
    while (true){
        if (b[x]==1 || j>=n) break;
        b[x] = 1;
        ans += x;
        c.push_back(x);
        x = a[x];
        j++;
    }

    if (j<n){
        int index = 0;
        rep(i,0,c.size()){
            if (c[i]==x){
                index = i;
                break;
            }
        }
        ll size = c.size()-index;
        rep(i,index,c.size()){
            if ((n-i-size)%size==0){
                ans += c[i]*((n-i-size)/size);
            }else{
                ans += c[i]*((n-i-size)/size+1);
            }
        }
    }
    
    cout<<ans<<endl;
}