#include<bits/stdc++.h>
#define ALL(c) begin(c), end(c)
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;

const int mod = 1e9+7;

int inv(int a, int m){
	assert(0<a);
	assert(a<m);
	return a==1 ? 1 : m-m*1LL*inv(m%a, a)/a;
}

struct mint{
	int x;
	mint(): x(0) {}
	mint(const auto &val): x(val%mod) { if(x<0) x+=mod; }
};

void operator+=(mint &a, const mint &b){ a.x+=b.x; if(a.x>=mod) a.x-=mod; }
mint operator+(mint a, const mint &b){ a+=b; return a; }
void operator-=(mint &a, const mint &b){ a.x-=b.x; if(a.x<0) a.x+=mod; }
mint operator-(mint a, const mint &b){ a-=b; return a; }
void operator*=(mint &a, mint b){ a.x = 1LL*a.x*b.x %mod; }
mint operator*(mint a, const mint &b){ a*=b; return a; }
mint operator/(const mint &a, const mint &b){ return mint(1LL*a.x*inv(b.x,mod)); }
mint operator""m(unsigned long long x){return mint(x);}
ostream& operator<<(ostream &o, const mint &m){ return o<<m.x; }



int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int n;
	
	cin>>n;
	vector<ll> a(n);
	for(auto &_ : a) cin>>_;
	
	
	auto s = accumulate(ALL(a), 0m);
	
	auto ss = 0m;
	for(ll x : a) ss+=x*x;
	
	cout<<(s*s - ss)/2<<endl;
	
	
	return 0;
}
