#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long>
#define sz size()
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ld long double

using namespace std;

int a, b, c;
int main() {
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	cin >> a >> b >> c;
	if((a * 100 + b * 10 + c) % 4  == 0) {
		cout << "YES";
	} else {

		cout << "NO";
	}
	return 0;
}