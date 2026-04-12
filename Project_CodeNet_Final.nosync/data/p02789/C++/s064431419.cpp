#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define Inf 1000000000
#define nmax_def 110000
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

int main() {
	int N, M;
	string ans = "Yes";
	cin >> N >> M;
	if (N != M)
		ans = "No";
	cout << ans << endl;


	return 0;
}