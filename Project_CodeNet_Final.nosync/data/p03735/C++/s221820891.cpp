#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<ll,ll>P;
#define INF (1LL<<61)
 
int n;
template <typename T>
class Rmq {
public:
	int n;
	vector<T> dat;

	void init(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		dat.resize(2 * n - 1, INF);//

	}

	void update(int k, T x) {
		k += n - 1;
		dat[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;//k/2でない注意
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}

	}
	T find(int a, int b) {
		return find0(a, b, 0, 0, n);
	}
	T find0(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)//等号が必要
			return INF;
		if (a <= l && r <= b)
			return dat[k];
		else {
			T x1, x2;
			x1 = find0(a, b, k * 2 + 1, l, (l + r) / 2);//ここはl,r
			x2 = find0(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(x1, x2);
		}
	}
};

int main(){
	scanf("%d ", &n);
	vector<P> v(n);
	rep(i, n) {
		scanf("%lld %lld ", &v[i].first, &v[i].second);
		if (v[i].first > v[i].second)
			swap(v[i].first, v[i].second);
	}
	
	
	sort(all(v));

	ll ans=INF; 
	
	
	Rmq<ll> lmin, lmax, rmin, rmax;
	lmin.init(n); lmax.init(n); rmin.init(n); rmax.init(n);
	rep(i, n) {
		lmin.update(i, v[i].first);
		lmax.update(i, -v[i].first);
		rmin.update(i, v[i].second);
		rmax.update(i, -v[i].second);

	}
	ans = min(ans, (-lmax.find(0, n) - lmin.find(0, n)) * (-rmax.find(0, n) - rmin.find(0, n)));
	rep(i, n) {
		lmin.update(i, v[i].second);
		lmax.update(i, -v[i].second);
		rmin.update(i, v[i].first);
		rmax.update(i, -v[i].first);
		ans = min(ans, (-lmax.find(0, n) - lmin.find(0, n)) * (-rmax.find(0, n) - rmin.find(0, n)));
	}
	cout << ans << endl;
	return 0;
}
