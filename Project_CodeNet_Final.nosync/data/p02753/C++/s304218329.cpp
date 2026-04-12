#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 4e4 + 5;
const int inf = 2e9 + 7;
int a[maxn], b[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	if (s[0] != s[1] || s[1] != s[2])cout << "Yes\n";
	else cout << "No\n";


	return 0;
}
