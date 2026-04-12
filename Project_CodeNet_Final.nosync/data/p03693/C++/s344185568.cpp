#include <bits/stdc++.h>
using namespace std;
#define fr(i, p, n) for(int i = (int )p; i < (int )n; i++)
#define frn(i, p, n) for(int i = (int )p; i <= (int )n; i++)
#define rev(i, n, p) for(int i = (int )n; i >= (int )p; i--)

typedef long long int LL;
typedef pair< int, int> ii;
const int mod = 1e9 + 7;
const int mx = 1e6;
const int i27 = 1 << 27;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
	int r, g, b;
	cin >> r >> g >> b;
	int a = r * 100 + g * 10 + b;
	if(a % 4) cout << "NO";
	else cout << "YES";
	return 0;
}