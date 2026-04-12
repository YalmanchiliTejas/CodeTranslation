//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef long long ijt;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

ijt func(vector<ijt> a, ijt mid) {
	ijt n = a.size();
	ijt cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > mid) {
			cnt += (a[i] - mid + n) / (n + 1);
		}
	}
	return cnt;
}
int main(void) {
	ijt n; cin >> n;
	vector<ijt> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(all(a)); reverse(all(a));
	ijt ub = a[0] + 1, lb = -(1ll << 59);
	while (ub - lb > 1) {
		
		ijt mid = (ub + lb) / 2;
		//cout << mid << " " << n - 1 - func(a, mid) << endl;
		if (mid <= n - 1 - func(a,mid)) {
			lb = mid;
		}
		else {
			ub = mid;
		}
	}
	cout << endl;
	//cout << ub << " " << 2 * n << endl;
	for (ijt i = ub + 2000; i >= ub - 2000; i--) {
		//cout << i << " " << n - 1 - func(a, i) << endl;
		if (i <= n - 1 - func(a, i)) {
			cout << func(a,i) << endl;
			break;
		}
	}

	return 0;
}