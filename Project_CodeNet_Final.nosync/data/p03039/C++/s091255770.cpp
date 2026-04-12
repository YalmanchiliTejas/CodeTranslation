#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

constexpr int MOD = 1e9+7;
struct mint
{
	int v;
	mint():v(0){}
	mint(int v):v((v+MOD)%MOD){}
	mint operator-()const{ return mint(0) - *this; }
	mint& operator+=(const mint& a){ if((v+=a.v)>=MOD) v-=MOD; return *this; }
	mint& operator-=(const mint& a){ if((v+=MOD-a.v)>=MOD) v-=MOD; return *this; }
	mint& operator*=(const mint& a){ (v*=a.v)%=MOD; return *this; }
	mint& operator/=(const mint& a){ (*this) *= a.inv(); return *this; }
	mint operator+(const mint& a)const{ return mint(*this) += a; }
	mint operator-(const mint& a)const{ return mint(*this) -= a; }
	mint operator*(const mint& a)const{ return mint(*this) *= a; }
	mint operator/(const mint& a)const{ return mint(*this) /= a; }
	bool operator<(const mint& a)const{ return v < a.v; }
	bool operator==(const mint& a)const{ return v == a.v; }
	mint pow(int k)const{ mint r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }
	mint inv()const{ return pow(MOD-2); }
	static mint comb(int n, int k) {
		if(n-k<k) k=n-k;
		mint num(1), dom(1);
		for(int i=0;i<k;i++) { num*=n-i; dom*=i+1; }
		return num/dom;
	}
};
std::istream& operator>>(std::istream&i,mint&a){ int t; i>>t; a=mint(t); return i; }
std::ostream& operator<<(std::ostream&o,const mint&a){ o<<a.v; return o; }


signed main() {
	int n,m,k;
	std::cin >> n >> m >> k;

	mint comb = mint::comb(n*m-2,k-2);

	mint sum = 0;
	for(int d=1;d<n;d++) sum+=mint(d)*mint(n-d)*mint(m*m)*comb;
	for(int d=1;d<m;d++) sum+=mint(d)*mint(m-d)*mint(n*n)*comb;

	print(sum);
	return 0;
}
