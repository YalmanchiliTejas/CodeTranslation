#include <bits/stdc++.h>
#define tam 505

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, k;
	string s;
	cin >> n >> s >> k;
	char a = s[k - 1];
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != a) {
			cout << "*";
		} else cout << a;
	}
	cout << "\n";
	return 0;
}
