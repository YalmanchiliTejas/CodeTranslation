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

// grid
//--------------------------------------------
VL dx = {0, 1, 0, -1};
VL dy = {1, 0, -1, 0};
VL dx2 = {-1, 0, 1, -1, 1, -1, 0, 1};
VL dy2 = {-1, -1, -1, 0, 0, 1, 1, 1};

//debug
//--------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//main code

char souti(char a, char b) {
	if (a == 'T' and b == 'F') {
		return 'F';
	}
	return 'T';
}

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	vector<char> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	char ans = s[0];
	for (int i = 1; i < n; i++) {
		ans = souti(ans,s[i]);
	}
	cout << ans << endl;
	return 0;
}

