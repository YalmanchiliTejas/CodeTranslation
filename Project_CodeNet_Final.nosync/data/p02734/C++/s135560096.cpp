#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

constexpr int MOD = 998244353;
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
	int n,s;
	std::cin >> n >> s;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	std::vector<mint> q(s+1,0);
	mint sum=0;
	rep(i,n) {
		q[0]+=1;
		std::vector<mint> q2(s+1,0);
		for(int j=s;j>=0;j--) {
			q2[j]+=q[j];
			if(j-a[i]>=0) q2[j]+=q[j-a[i]];
		}
		sum+=q2[s];
		q=q2;
	}
	print(sum);
	return 0;
}
