#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const ll mod = 1e9+7;

const ll d = 40;
const ll mm = 1e5+5;

//ll to[d][mm];

int main(){
    ll n,m,x;
    cin >> n >> x >> m;
    ll xx = x;
    ll xxx = x;
    set<ll> s;
    ll tot = 0;
    ll cnt = 0;
    while(true){
        if(s.count(x)) break;
        tot+=x;
        s.insert(x);
        cnt++;
        x=(x*x)%m;
        //cout << x << endl;
    }
    ll totot = 0;
    ll cntt = 0;
    while(true){
        if(xx == x) break;
        totot+=xx;
        //s.insert(x);
        cntt++;
        xx=(xx*xx)%m;
    }
    //cout << tot << " " << cnt << " " << totot << " " << cntt << endl;
    ll ans = 0;
    if(n <= cntt){
    for(ll i=0; i<n; i++){
        ans+=xxx;
        //s.insert(x);
        //cntt++;
        xxx=(xxx*xxx)%m;
    }
    }
    else{
        ans += totot+((n-cntt)/(cnt-cntt))*(tot-totot);
        for(ll i=0; i<(n-cntt)%(cnt-cntt); i++){
            ans+=x;
            x=(x*x)%m;
        }
    }
    cout << ans << endl;
}