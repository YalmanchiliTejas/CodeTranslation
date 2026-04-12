#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll barg[55], pathi[55]; 

ll num(int N, ll X) {
	if (N==0) return (X<=0)? 0 : 1;
	else if (X<=1+barg[N-1]) return num(N-1,X-1);
	else return pathi[N-1] + 1 + num(N-1,X-2-barg[N-1]); 
}

int main() {
	int n; ll x;
	cin >> n >> x;
	barg[0] = pathi[0] = 1;
	rep(i,n) {
		barg[i+1] = 2 * barg[i] + 3;
		pathi[i+1] = 2 * pathi[i] + 1;
 	}
	cout << num(n,x) << endl;
	return 0;
}