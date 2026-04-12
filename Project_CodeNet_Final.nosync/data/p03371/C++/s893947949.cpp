#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	i64 ans1 = 0;
	ans1 += x * a;
	ans1 += y * b;

	i64 ans2 = 0;
	ans2 += (max(x, y)) * 2 * c;

	i64 ans3 = 0;
	int tmp = min(x, y);
	ans3 += (min(x, y)) * 2 * c;
	x -= tmp;
	y -= tmp;
	ans3 += x * a;
	ans3 += y * b;
	cout << min(min(ans1, ans2), ans3) << endl;
	return 0;
}