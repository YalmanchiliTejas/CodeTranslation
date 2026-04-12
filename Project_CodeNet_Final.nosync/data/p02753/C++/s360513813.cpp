#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<math.h>
#include<numeric>
#include<iomanip>
#define rep(i, n) rep2(i,0,n)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define PI acos(-1);
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
//scanf("%d", &a); '\n'; cout << fixed << setprecision(10);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB")cout << "No";
	else cout << "Yes";
}