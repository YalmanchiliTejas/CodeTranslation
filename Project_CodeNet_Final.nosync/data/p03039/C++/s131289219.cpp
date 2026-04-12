#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

template<int M>
class Combination
{
public:
  int n;
  vector<int> fac, finv;

  Combination(int n_) : n(n_), fac(n_), finv(n_)
  {
    fac[0] = 1;
    for(int i = 1; i < n; i++) fac[i] = fac[i-1]*i%M;
    finv[n-1] = pow(fac[n-1], M-2);
    for(int i = n-1; i > 0; i--) finv[i-1] = finv[i]*i%M;
  }

  int pow(int a, int b)
  {
    if(b == 0) return 1; 
    return pow(a*a%M, b/2)*(b%2?a:1)%M;
  }

  int C(int a, int b)
  {
    if(b < 0 or a < b) return 0;
    return fac[a]*finv[a-b]%M*finv[b]%M;
  }

  int P(int a, int b)
  {
    if(b < 0 or a < b) return 0;
    return fac[a]*finv[a-b]%M; 
  }

  int H(int a, int b){
    if(a == 0 and b == 0) return 1;
    return C(a+b-1, b);
  }
};

signed main(){
	Combination<mod> comb(200010);
	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	rep(i, 0, n){
		int d = i*(i+1)/2%mod;
		d = d*m%mod*m%mod;
		ans += d;
	}
	rep(i, 0, m){
		int d = i*(i+1)/2%mod;
		d = d*n%mod*n%mod;
		ans += d;
	}

	cout << ans%mod*comb.C(n*m-2, k-2)%mod << endl;

	return 0;
}
