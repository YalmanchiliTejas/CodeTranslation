//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MOD = 1000000007;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//main code


int main(int argc, char const* argv[])
{
	LL n,x;
	cin >> n >> x;
	n++;
	VL p_all(n);
	VL height(n);
	p_all[0] = 1;
	height[0] = 1;
	for (int i = 1; i < n; i++) {
		p_all[i] = 2*p_all[i-1] + 1;
		height[i] = 2*height[i-1] + 3;
	}
	LL ans = 0;
	for (int l = n-1; l >= 1; l--) {
		if (x >= height[l] - 1) {
			ans += p_all[l-1] * 2 + 1;
			break;
		}
		else if (x >= height[l] / 2) {
			ans += p_all[l-1] + ((x > height[l] / 2) ? 1 : 0);
			x -= 1 + height[l-1] + ((x > height[l] / 2) ? 1 : 0);
		}
		else {
			x--;
		}
		if (x <= 0) {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
