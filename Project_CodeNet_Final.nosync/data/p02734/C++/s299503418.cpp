/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/*
 * Modint struct
 * library author : @snuke
 * */
const int mod = 998244353;
struct mint {
  long long x; // typedef long long ll;
  mint(long long x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) { if((x+=a.x)>=mod)x-=mod;return *this;}
  mint& operator-=(const mint a) { if((x+=mod-a.x)>=mod)x-=mod; return *this;}
  mint& operator*=(const mint a) { (x *=a.x)%=mod; return *this;}
  mint operator+(const mint a) const { mint res(*this);return res+=a;}
  mint operator-(const mint a) const { mint res(*this);return res-=a;}
  mint operator*(const mint a) const { mint res(*this);return res*=a;}
  mint pow(ll t) const {
    if (!t) return 1;mint a = pow(t>>1);a*=a;
    if (t&1) a *= *this;return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return (*this) *= a.inv();}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
namespace ModintUtil{
    mint mod_pow(long long p,long long q){mint res = p;return res.pow(q);}
    mint frac(long long p,long long q){ mint P = (mint)p; P /= (mint)q; return P; } // p/q
    mint frac(mint p,mint q){ p /= q; return p; }
    vector<mint> make_facl(long long N){ 
        vector<mint> ret(N+1);
        for(int i = 0;i <= N;i++){ if(i == 0)ret[i] = (mint)1; else ret[i] = ret[i-1] * (mint)i; }
        return ret;
    }
}
using namespace ModintUtil;
/////////////////////////////////////////////////////////////////////////////
/*
  modの値は1e9 + 7か998244353か任意modか、要チェック！！
*/

vector<vector<mint>> dp(3030,vector<mint>(3030,0));

int main(int argc, char const *argv[])
{
	ioboost();

	ll n,s;cin >> n >> s;
	vector<ll> a(n);
	rep(i,n)cin >> a[i];

	mint ans = 0;
	for(int i = n-1;i >= 0;i--){
		vector<mint> poly = dp[i];
		poly[0]+=1;

		vector<mint> newpoly(3030,0);
		for(int j = 0;j <= s;j++){
			newpoly[j] += poly[j];
			if(j - a[i] >= 0)newpoly[j] += poly[j - a[i]];
		}		

		ans += newpoly[s];
		if(i > 0)dp[i-1] = newpoly;
	}
	cout << ans << '\n';
	return 0;
}