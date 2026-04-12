#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<int> VI;
const ll MOD = 1000000007;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
	int n;
	cin >> n;
	VI p;
	int a, sj;
	REP(i, n) {
		cin >> a;
		if (i == 0)
			p.push_back(a);
		else {
			sj = distance(p.begin(), lower_bound(p.begin(), p.end(), a));
			if(sj == 0)
				p.insert(p.begin(), a);
			else {
				p[sj - 1] = a;
			}
		}
	}
	cout << p.size();
}