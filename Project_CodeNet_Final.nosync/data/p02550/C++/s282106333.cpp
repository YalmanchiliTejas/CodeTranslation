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

set<ll>st;
vector<ll>lp;
ll n, x, m, sum, y;

int main(){
	setIO();
	cin >> n >> x >> m;
	y = x;
	st.insert(x);
	for (int i = 0; i <= m; i++){
		x = (x*x)%m;
		if (st.count(x))
			break;
		st.insert(x);
	}
	lp.emp(x); ll z = (x*x)%m, lsum = x;
	while (z != x){
		lsum += z;
		lp.emp(z);
		z = (z*z)%m;
	}
	for (int i = 1; i <= n; i++){
		if (y == x){
			ll loop = (n-i+1)%(int)lp.size(), summ = 0;
			for (int j = 0; j < loop; j++)
				summ += lp[j];
			cout << sum+summ+(n-i+1)/(int)lp.size()*lsum << endl;
			return 0;
		}
		sum += y;
		y = (y*y)%m;
	}
	cout << sum << endl;
}