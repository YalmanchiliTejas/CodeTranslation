#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9+7;
//const ll MOD = 998244353;
//const ll MOD = 924844033;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
const double EPS = 1e-5;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

#ifdef DEBUG
#define OUTPUT(x) (output(x), outendl())
#else
#define OUTPUT(x) (void)0
#endif

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){ return modpow(x, MOD-2); }
ll in(){ ll x; scanf("%lld",&x); return x; }
string in_s(){ string res;cin >> res;return res; }
bool was_output = false;
template<class t>
void output(t a){ if(was_output)cout << " "; cout << a; was_output = true; }
void outendl(){ was_output = false; cout << endl; }

int n;
vvector<ll> line;

void input(){
    n = in();
    line.resize(n,vector<ll>(2));
    foreach(i,line){
        i[0] = in();
        i[1] = in();
    }
}

ll cul_dis(multiset<ll> &s){
    return *s.rbegin() - *s.begin();
}

ll solve(){
	ll res = INFLL;
	multiset<ll> mins;
	multiset<ll> maxs;
    foreach(i,line){
        if(i[0]>i[1])swap(i[0],i[1]);
        mins.insert(i[0]);
        maxs.insert(i[1]);
    }
    sort(all(line));
    res = cul_dis(maxs) * cul_dis(mins);
    foreach(i,line){
        mins.erase(mins.find(i[0]));
        maxs.insert(i[0]);
        mins.insert(i[1]);
        maxs.erase(maxs.find(i[1]));
        chmin(res,cul_dis(maxs)*cul_dis(mins));
    }
    return res;
}

int main(){
    input();
    cout << solve() << endl;
	return 0;
}
