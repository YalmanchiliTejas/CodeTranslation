#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
void IO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SZ(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
	IO();
	int x;
	cin >> x;
	if (x >= 30) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}
