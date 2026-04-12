#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin >> a;
    string ans = "NO";
    if(a == 3 || a == 5 || a == 7){
        ans = "YES";
    }

	cout << ans << endl;
	return 0;
}