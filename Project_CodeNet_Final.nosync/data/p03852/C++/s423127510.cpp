#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
#define int long long
#define all(vec) vec.begin(), vec.end()
#define dbg(x) cerr << #x << " = " << (x) << endl
#define yn(b) cout << ((b) ? "Yes" : "No") << endl
#define YN(b) cout << ((b) ? "YES" : "NO") << endl
#define isEven(t) t % 2 == 0

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	char c;
	cin>>c;

	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}

	return 0;
}