#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

LL pw(LL a , LL b , LL mod){
	LL z = 1;
	for(; b > 0 ; b >>= 1){
		if(b&1) (z *= a) %= mod;
		(a *= a) %= mod;
	}
	return z;
}

void NTT(vector<LL> &a , LL mod , LL pr , bool rev = 0){
	int n = a.size();
	int lg = 0;
	for(int i = 0 ; 1 << i < n ; ++i) ++lg;
	for(int i = 0 ; i < n ; ++i){
		int j = 0;
		for(int k = 0 ; k < lg ; ++k) j |= (i >> k & 1) << (lg - 1 - k);
		if(i < j) swap(a[i] , a[j]);
	}
	for(int i = 1 ; i < n ; i *= 2){
		LL wb = pw(pr,(mod-1)/i/2,mod);
		if(rev) wb = pw(wb,mod-2,mod);
		LL w = 1;
		for(int j = 0 ; j < i ; ++j){
			for(int k = 0 ; k < n ; k += i * 2){
				LL s = a[j + k];
				LL t = (a[j + k + i] * w) % mod;
				a[j + k] = (s + t) % mod;
				a[j + k + i] = (s - t + mod) % mod;
			}
			(w *= wb) %= mod;
		}
	}
	if(rev){
		LL inv = pw(n,mod-2,mod);
		for(int i = 0 ; i < n ; ++i) (a[i] *= inv) %= mod;
	}
}
	
void conv(vector<LL> &a , vector<LL> b , LL mod){
	LL pr = 3;
	int s = a.size() + b.size() - 1;
	int t = 1;
	while(t < s) t *= 2;
	a.resize(t);
	b.resize(t);
	NTT(a,mod,pr);
	NTT(b,mod,pr);
	for(int i = 0 ; i < t ; ++i) (a[i] *= b[i]) %= mod;
	NTT(a,mod,pr,1);
	a.resize(s);
}

const LL mod = 998244353;
const int MC = 10010;
LL fct[MC];
LL inv[MC];
char A[MC] , B[MC];
vector<LL> ans;
vector<LL> base;

void build(){
	fct[0] = fct[1] = 1;
	repp(i,2,MC+1){
		fct[i] = fct[i-1] * i % mod;
	}
	LL x = fct[MC];
	inv[MC] = 1;
	for(int i = mod - 2 ; i > 0 ; i >>= 1){
		if(i % 2 == 1) (inv[MC] *= x) %= mod;
		(x *= x) %= mod;
	}
	repm(i,MC,0){
		inv[i-1] = inv[i] * i % mod;
	}
}

int main(){
	build();
	scanf("%s %s" , A , B);
	int x = 0 , y = 0;
	for(int i = 0 ; A[i] ; ++i){
		if(A[i] == '0') continue;
		if(A[i] == B[i]) ++x;
		else ++y;
	}
	repp(i,0,x+1){
		ans.PB(1);
		base.PB(inv[i+1]);
	}
	for(int i = y ; i > 0 ; i >>= 1){
		if(i%2){
			conv(ans,base,mod);
			ans.resize(x+1);
		}
		conv(base,base,mod);
		base.resize(x+1);
	}
	printf("%lld\n" , ans[x] * fct[x] % mod * fct[y] % mod * fct[x+y] % mod);
	return 0;
}
