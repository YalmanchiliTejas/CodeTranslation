
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
typedef long long       ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define mt                make_tuple
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define forr(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define deb(x)			  cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x)             (int)x.size()
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int INF = 1234567890;

ll MOD = 1e9 + 7;

ll modPow(ll b, ll e) {
	if (e == 0) return 1;
	ll res = modPow(b, e>>1);
	res = res * res % MOD;
	if (e&1) res = b * res % MOD;
	return res;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    cin >> n;
    ll sum = 0;
    ll sq = 0;
    fore(i, 0, n) {
    	ll x;
    	cin >> x;
    	sum += x;
    	sq += x*x;
    	sum %= MOD;
    	sq %= MOD;
    }
    ll ans = ((sum*sum%MOD) - sq + MOD) % MOD;
    ans = ans * modPow(2, MOD-2) % MOD;
    cout << ans << '\n';
    return 0;
}
// Dinosaurs are cool!