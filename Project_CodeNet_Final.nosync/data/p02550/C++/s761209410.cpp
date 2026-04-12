#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, x, m;
	cin >> n >> x >> m;
	vector<ll> A;
	A.push_back(x);
	set<ll> F;
	F.insert(x);
	ll st = -1;
	while (true) {
		ll next = (A.back() * A.back()) % m;
		if (F.find(next) != F.end()) {
			st = next;
			break;
		} else {
			A.push_back(next);
			F.insert(next);
		}
	}
	ll ans = 0;
	vector<ll> B;
	for (int i = 0; i < (int) A.size(); i++) {
		if (A[i] == st) {
			for (int j = i; j < (int) A.size(); j++) B.push_back(A[j]);
			break;
		} else {
			n--;
			ans += A[i];
			if (n == 0) {
				cout << ans << "\n";
				return 0;
			}
		}
	}
	ll sum = 0;
	for (ll b: B) sum += b;
	ll k = n / (ll) B.size();
	ll r = n % (ll) B.size();
	ans += sum * k;
	for (int i = 0; i < r; i++) {
		ans += B[i];
	}
	cout << ans << endl;
}

