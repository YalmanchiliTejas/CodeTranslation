#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rep1(i,n) for(int (i) = 1; (i) <= (n); ++(i))
#define repU(i,bottom,ceiling) for(auto (i) = (bottom); (i) <= (ceiling); ++(i))
#define repD(i,ceiling,bottom) for(auto (i) = (ceiling); (i) >= (bottom); --(i))
#define repS(n) for(int s = 0; s < 1 << n; ++s)
#define repV(i,v) for(auto (i) = begin(v); (i) < end(v); ++(i))
#define all(v)  begin(v),end(v)
#define clr(v) fill(all(v),0)
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define parity(a,b) (((a) & 1)^((b) & 1)^1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF = -1 + (1<<30);
const int MOD = (int)1e9 + 7;

template<class T,class U> auto LB(T v, U in){ return lower_bound(all(v), in); }

template<class T,class U> auto UB(T v, U in){ return upper_bound(all(v), in); }

ull next_subset(ull subset){
	ull tem = subset + (subset & -subset);
	ull btm = (~tem & subset) / (subset & -subset) >> 1;
	return btm | tem;
}

ll Pow(ll n, ll m, int mod = MOD){
	ll res = 1,pow = n % mod;
	while(m) {
		if(m & 1) res = (res * pow) % mod;
		pow = (pow * pow) % mod;
		m >>= 1;
	}
	return res;
}

vector<ll> Frac(int range, int mod = MOD){
	vector<ll> frac(range + 1);
	frac[0] = 1;
	for(int i = 1; i <= range; ++i) frac[i] = frac[i - 1] * i % mod;
	return frac;
}

vector<ll> frac;

ll Comb(int n, int m, int mod = MOD){
	if(n < m || m < 0) return 0;
	ll rev = Pow(frac[m] * frac[n-m] % mod, mod - 2, mod);
	return rev * frac[n] % mod;
}

int N,M;
ll A = 0;

void solve(){
	
	ll comb[3001],power1[3001],power2[3001];
	
	frac = Frac(N,M);
	rep(i,N/2+1) comb[i] = comb[N-i] = Comb(N,i,M);
	
	power1[N] = 1;
	rep(i,N) power1[N-i-1] = power1[N-i] * 2 % M;
	
	power2[N] = 2;
	rep(i,N) power2[N-i-1] = power2[N-i] * power2[N-i] % M;
	
	vector<ll> s(1,1);
	int b = 1;
	
	rep(i,N+1){
		ll p = power1[i];
		ll t = 1;
		ll ways = 0;
		
		rep(j,i+1){
			ways += s[j] * t % M * power2[i] % M;
			ways %= M;
			t = t * p % M;
		}
		
		A += comb[i] * ways % M * b;
		A = (A + M) % M;
		
		s.pub(1);
		repD(j,i,1) s[j] = (s[j] * (j+1) + s[j-1]) % M;
		
		b *= -1;
	}
	
	cout<<A<<endl;
	
	return;
}

void input(){

	cin>>N>>M;
	
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	input();
	solve();
	return 0;
}



