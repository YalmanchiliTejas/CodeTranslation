#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) (int)((a).size())
#define all(c) (c).begin(), (c).end()
#define debug(v) {for (auto z : v) {cerr << z << ' ';} cerr << endl;}

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (char c : s)
		if (c == 'A') a++;
		else b++;
	if (a > 0 && b > 0) puts("Yes");
	else puts("No");
}
