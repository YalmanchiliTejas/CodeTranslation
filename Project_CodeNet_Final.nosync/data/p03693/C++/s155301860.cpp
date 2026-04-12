#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string r, g, b;
	cin >> r >> g >> b;
	string T = r + g + b;
	int res = stoi(T);
	if (res % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}