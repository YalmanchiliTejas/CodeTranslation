#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define EPS 1e-9
#define X real()
#define Y imag()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using point = pair<double, double>;
using Vector = complex<double>;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(char c : s) {
		if(c == 'A') ++a;
		else ++b;
	}
	if(a && b) cout << "Yes\n";
	else cout << "No\n";
    return 0;
}
