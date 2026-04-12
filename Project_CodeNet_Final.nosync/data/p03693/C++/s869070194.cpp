#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define mp make_pair
#define EPS (int)1e-9
#define PI acos(-1)
#define endl '\n'
#define pb push_back
#define fi first
#define se second

using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 1000000007;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, g, b;
	cin >> r >> g >> b;

	int t = r*100 + g*10 + b;
	if(t % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;	
}