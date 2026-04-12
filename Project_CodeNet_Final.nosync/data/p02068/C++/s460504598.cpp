#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

bool noPrime[1111111];
void makeIsp(){
    noPrime[0] = noPrime[1] = true;
    for(int i = 2;i < 1111111;i++){
        if(noPrime[i])continue;
        for(int j = 2 * i;j < 1111111;j += i){
            noPrime[j] = true;
        }
    }
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    makeIsp();

    ll n;cin >> n;
    ll ans = 0;
    vector<ll> v(n);
    REP(i, n){
        cin >> v[i];
        if(v[i] > 1)ans = max(ans, v[i]);
    }

    REP(i, 1111111){
        if(noPrime[i])continue;
        ll now = 0;
        REP(j, n){
            if(v[j] % i == 0)now += v[j];
        }
        ans = max(ans, now);
    }

    REP(i, n){
        ll now = 0;
        if(v[i] == 1)continue;
        REP(j, n){
            if(v[j] % v[i] == 0)now += v[j];
        }
        ans = max(ans, now);
    }

    cout << ans << endl;
	return 0;
}

