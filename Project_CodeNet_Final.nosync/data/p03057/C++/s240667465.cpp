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
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;
/*
0-index
functionの中を書いて使う
宣言の時に単位元を書く
*/
template<typename T>
struct segtree{
	int n;
	vector<T> dat;
	T ZERO;
	function<T(T,T)> func;
	segtree(int n_, function<T(T,T)> func_, T zero):func(func_), ZERO(zero){
	  n = 1;
	  while(n < n_)n*=2;
	  dat.resize(2*n);
	  for(int i = 0;i < 2*n;i++)dat[i] = ZERO;
	}
	void update(int k, T a){
	  k += n - 1;dat[k] = a;
	  while(k > 0){
		k = (k-1)/2;
		dat[k] = func(dat[k*2+1],dat[k*2+2]);
	  }
	}

	void set(int k, T a) {
		k += n - 1;dat[k] = a;
	}

	void build(){
		for(int i = n - 2;i >= 0;i--){
			dat[i] = func(dat[2 * i + 1], dat[2 * i + 2]);
		}
	}

	T get(int k){return dat[k+n-1];}

	T que(int a,int b){
		T L = ZERO,R = ZERO;
		int A = a + n - 1;
		int B = b + n - 1;
		while(A < B){
			if((A & 1) == 0)L = func(L,dat[A++]);
            if((B & 1) == 0)R = func(dat[--B],R);
            A = A >> 1;
            B = B >> 1;
		}
		return func(L,R);
	}
};


int getmin(string str){
	char c = str[0];
	bool isFirst = true;
	int cou = 0;
	int ret = INF;
	REP(i, str.size()){
		if(str[i] == c)cou++;
		else {
			if(isFirst && cou % 2 == 0)cou++;
			if(cou % 2)ret = min(ret, cou);
			isFirst = false;
			cou = 0;
		}
	}

	return ret;
}

bool oneKind(string str){
	REP(i, str.size())if(str[0] != str[i])return false;
	return true;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	ll n, m;cin >> n >> m;
	string str;cin >> str;
	ll ans = 0;

	int k = getmin(str);
	segtree<ll> seg(n, [](ll a, ll b){return (a + b) % MOD;}, 0);

	seg.update(0, 1);

	if(oneKind(str)){
		for(ll i = 2;i < n;i++){
			ll l = max(0LL, i - k - 1);
			ll r = i - 1;
			seg.update(i, seg.que(l, r));
		}
		REP(i, n-1){
			if(n - (i + 1) <= k){
				//cout << "pass " << seg.get(i) * (n - i) % MOD << endl;
				ans = (ans + seg.get(i) * (n - i) % MOD) % MOD;
			}
		}
		ans = (ans + 1) % MOD;
	}
	else {
		for(ll i = 2;i < n;i++){
			if(i % 2)continue;
			ll l = max(0LL, i - k - 1);
			ll r = i - 1;
			seg.update(i, seg.que(l, r));
		}

		//REP(i, n)cout << seg.get(i) << " ";cout << endl;
		REP(i, n-1){
			if(n - (i + 1) <= k && ((n - (i + 1)) % 2)){
				//cout << "pass " << seg.get(i) * (n - i) % MOD << endl;
				ans = (ans + seg.get(i) * (n - i) % MOD) % MOD;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
