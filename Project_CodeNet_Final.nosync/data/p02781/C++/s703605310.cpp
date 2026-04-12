#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int power(int a, int b) {
	int result = 1;
	while(b) {
		if(b % 2) result = (result * a) % P;
		a = (a * a) % P;
		b /= 2;
	}
	
	return result;
}

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

void solve() {
	string s;
	cin >> s;
	
	int n = s.length(), k;
	cin >> k;
	
	if(n < k) {
		cout << 0 << endl;
		return;
	}
	
	int ans = C(n, k) * power(9, k), digits = 0;
	for(int i = 0; i < n && k - digits; i++) {
		int d = s[i] - '0';
		ans -= (9 - d) * C(n - (i + 1), k - digits - 1) * power(9, k - digits - 1);
		if(d != 0) digits++;
	}	
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}