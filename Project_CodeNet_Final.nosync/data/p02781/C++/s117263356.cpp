#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <cctype>
#include <climits>

using namespace std;

using ll = long long int;
using ii = pair<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;


#define mp(a,b) make_pair(a,b)

const int MOD = 1000 * 1000 * 1000 + 7;

ll cont(string & num, int idx, int kact, vector<vvi> & m, int s) {
	if (kact == 0) return 1;
	else if (idx == num.size() && kact > 0) return 0;
	//else if (m[idx][kact][s] != -1) return m[idx][kact][s];
	else if (s == 0) {
		ll soluciones = 0;
		if (num[idx] != '0') {
			soluciones += cont(num, idx + 1, kact - 1, m, 0);
			soluciones += (num[idx] - '0' - 1) * cont(num, idx + 1, kact - 1, m, 1);
			soluciones += cont(num, idx + 1, kact, m, 1);
		}
		else {
			soluciones += cont(num, idx + 1, kact, m, 0);
		}
		
		
		m[idx][kact][s] = soluciones;
		return soluciones;
	}
	else {
		ll soluciones = 0;
		soluciones += 9 * cont(num, idx + 1, kact - 1, m, 1);
		soluciones += cont(num, idx + 1, kact, m, 1);

		m[idx][kact][s] = soluciones;
		return soluciones;
	}
}

bool res() {
	string s;
	int k;
	cin >> s >> k;
	if (!cin) return false;

	vector<vvi> m(s.size() + 1, vvi(k + 1, vi(2, -1)));
	ll sol = cont(s, 0, k, m, 0);
	cout << sol << '\n';

	return true;
}

int main() {
	while (res()) {}
	return 0;
}