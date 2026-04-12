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

VL a = {1};
VL p = {1};

LL dfs(LL n,LL x) {
	// レベル0はパティ1枚
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	// レベルn(>0)の時
	//
	if (x > a[n-1]+2) {
		return dfs(n-1,x - a[n-1] - 2) + p[n-1] + 1;
	}
	if (x == a[n-1]+2) {
		return p[n-1] + 1;
	}
	return dfs(n-1,x-1);
}

int main(int argc, char const* argv[])
{
	LL n,x;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		a.push_back(a[i]*2+3);
		p.push_back(p[i]*2+1);
	}
	cout << dfs(n,x) << endl;
	return 0;
}
