#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repab(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
#define endl "\n"

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//--//--//--//--//--//--//--//--//--//--//--//



int main() {
	int n;
	ll ans = 0;
	cin >> n;
    vec<ll> a(n);
	vec<ll> s(n+1,0);
	
	rep(i, n){
		cin >> a[i];
		s[i+1] = s[i] + a[i];
	}
	rep(i, n){
		ans += a[i] * ((s[n] - s[i+1]) % MOD) % MOD;
	}
	cout << ans%MOD << endl;
}