#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long   ll;
typedef long double ld;

typedef pair<ll, ll>    pll;
typedef pair<ll, int>   pli;
typedef pair<int, int>  pii;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll>  vll;

const int Inf = (int) 1e9;
const ll  InfL = (ll)  1e18;

const int MaxN = (int) 2e5 + 5;

int n, a[MaxN], b[MaxN];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);

	for (int i = 0; i < n; i++)
		if (a[i] >= b[n/2]) cout << b[n/2 - 1] << endl;
		else cout << b[n/2] << endl;

	return 0;
}
