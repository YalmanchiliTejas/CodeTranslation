#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x,y,z) max((x),max((y),(z)))
#define tmin(x,y,z) min((x),min((y),(z)))
typedef long long ll; ll MM = 1000000000;ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y) {if (y == 0) return x;else return GCD(y, x % y);}
ll LCM(ll x, ll y) { return x / GCD(x, y) * y;}
//cout << fixed << setprecision(10);
ll fac(ll x){if(x==0) return 1;  return x*fac(x-1);}

int main(){
    set<ll> t, y;
    ll h, w; cin>>h>>w;
    vector<vector<char>>a(h, vector<char>(w));
    rep(i,h){
        ll cnt=0;
        rep(j,w){
            cin>>a[i][j];
            if(a[i][j]=='#') cnt++;
        }
        if(cnt==0) y.insert(i);
    }
    rep(i,w){
        ll cnt=0;
        rep(j,h){
            if(a[j][i]=='#') cnt++;
        }
        if(cnt==0) t.insert(i);
    }

    rep(i,h){
        if(y.count(i)) continue;
        rep(j,w){
            if(t.count(j)) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
}