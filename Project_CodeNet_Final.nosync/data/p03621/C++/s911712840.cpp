#include <bits/stdc++.h>
using namespace std;
#define vll vector<ll>
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 1e4 + 10, mod = 998244353;
const ll mod2 = mod * 1ll * mod;
const int CUTOFF = 1000;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

inline void add(ll & x, ll y, ll z){    
    x += y * z;
    if(x >= mod2) x -= mod2;
}
inline void naive_mul(vll & a, vll & b){
    vll c(a.size() + b.size() - 1);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            add(c[i + j], a[i], b[j]);
    for(int i = 0; i < c.size(); i++) c[i] %= mod;
    a = c;
}
inline void ADD(ll & a, ll b){
    a += b;
    if(a >= mod) a -= mod;
}
inline int get(vector<ll> & v, int i){
    return ((i >= v.size()) ? 0 : v[i]);
}
void Karatsuba(vll & a, vll & b){
    int sa = a.size(), sc = 2 * sa - 1;
    if(sa <= CUTOFF){
        naive_mul(a, b);
        return;
    }
    
    int h = a.size() >> 1;

    vll a2(a.begin(), a.begin() + h);
    vll a1(a.begin() + h, a.end());
    vll b2(b.begin(), b.begin() + h);
    vll b1(b.begin() + h, b.end());
    vll sma(max(a1.size(), a2.size()));

    for(int i = 0; i < a1.size(); i++){
        sma[i] = add(get(a1, i), get(a2, i));
    }

    Karatsuba(a1, b1); // a1 * b1
    Karatsuba(a2, b2); // a2 * b2
    b1.resize(max(b1.size(), b2.size()));
    for(int i = 0; i < b1.size(); i++){
        b1[i] = add(get(b1, i), get(b2, i));
    }

    Karatsuba(sma, b1); // (a1 + a2) * (b1 + b2)
    int sz = sa + sa - 1;
    a.clear();
    a.resize(sz);
    for(int i = 0; i < a1.size(); i++) ADD(a[i + (h << 1)], a1[i]);
    for(int i = 0; i < a2.size(); i++) ADD(a[i], a2[i]);
    for(int i = 0; i < sma.size(); i++){
        ADD(a[i + h], sub(sma[i], add(get(a1, i), get(a2, i))));
    }
}

void karatsuba(vll & a, vll & b){
    int sa = a.size(), sb = b.size(), sc = a.size() + b.size() - 1;
    if(sa * 1ll * sb <= CUTOFF * CUTOFF|| min(sa, sb) <= 10){
        naive_mul(a, b);
        return;
    }
    if(a.size() < b.size()) a.resize((int)b.size());
    else b.resize((int)a.size());
    Karatsuba(a, b);
    a.resize(sc);
}

int G[N];
set<int> a, b;
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
void truncate(vll & v, int n){
	if(v.size() > n) v.resize(n);
}
void polypower(vll & a, int n, int mx){
	vll x = {1};
	for(; n; n >>= 1, karatsuba(a, a), truncate(a, mx)) if(n & 1) karatsuba(x, a), truncate(x, mx);
	a = x;		
}
int main(){
	pre();
	string A, B;
	cin >> A >> B;
	int n = A.length();
	for(int i = 1; i <= n; i++){
		if(A[i - 1] == '1') a.insert(i);
	}
	for(int i = 1; i <= n; i++){
		if(B[i - 1] == '1') b.insert(i);
	}
	int m = 0;
	for(int i : b) if(!a.count(i)) m++;
	n = b.size();
	G[0] = 1;
	for(int k = 1; k < N; k++){
		for(int r = 1; r <= k; r++){
			G[k] = add(G[k], mul(G[k - r], mul(fact[k - 1], invfact[k - r])));
		}
	}
	vll poly(n + 1);
	for(int i = 0; i <= n; i++)
		poly[i] = invfact[i + 1];
	polypower(poly, m, n + 1);
	int ans = 0;
	for(int k = 0; k <= n - m; k++){
		int term1 = mul(fact[n - m - k], G[n - m - k]);
		int term2 = mul(get(poly, k), mul(fact[m], mul(fact[k], fact[m + k])));
		int term3 = mul(C(n - m, k), C(n, m + k));
		ans = add(ans, mul(term1, mul(term2, term3))) ;
	}
	printf("%d\n", ans);
}