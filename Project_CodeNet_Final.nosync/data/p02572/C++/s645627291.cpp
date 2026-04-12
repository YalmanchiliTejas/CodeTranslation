#include <bits/stdc++.h>

#define fst first
#define snd second
#define ll long long
#define ld long double
#define pb push_back
#define emp emplace_back
#define pii pair<int, int>
#define usg unsigned
#define sg signed
#define mp make_pair

using namespace std;

void setIO(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
}

const ld PI = 4*atan((ld)1);
const int INF = 1e9+7;
const ll _INF = 1e18+7;
const int mxn = 2e5+7;

ll a[mxn], pf[mxn], ans = 0;

int main(){
	setIO();
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		pf[i] = (a[i]+(i?pf[i-1]:0))%INF;
	}
	for (int i = 1; i < n; i++){
		ans = (ans+(pf[i-1]*a[i])%INF)%INF;
	}
	cout << ans%INF << endl;
}