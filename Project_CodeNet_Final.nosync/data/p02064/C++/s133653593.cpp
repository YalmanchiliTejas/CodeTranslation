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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

    ll n, s, t;cin >> n >> s >> t;
    cout << "? " << s << " " << t << endl;
    ll passDist;cin >> passDist;

    vector<pair<P, ll>> v;
    for(int i = 1;i <= n;i++){
        ll a, b;
        cout << "? " << s << " " << i << endl;
        cin >> a;
        cout << "? " << i << " " << t << endl;
        cin >> b;
        if(a + b == passDist){
            v.EB(MP(a, b), i);
        }
    }

    sort(ALL(v));
    vector<int> ans;
    ll now = s;
    ll nowDist = 0;
    REP(i, v.size()){
        ll id = v[i].SE;
        ll it = v[i].FI.SE;
        cout << "? " << now << " " << id << endl;
        ll a;cin >> a;
        if(nowDist + a + it == passDist){
            ans.PB(id);
            nowDist += a;
            now = id;
        }
    }

    cout << "! ";
    REP(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;

	return 0;
}

