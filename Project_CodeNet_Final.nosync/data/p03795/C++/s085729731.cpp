// In The Name Of Allah
// Mehrkish Makuei

#include <bits/stdc++.h>

#define pb push_back
#define debug1(x) cerr << #x << " : " << x << endl;
#define debug2(x, y ) cerr << #x << " : " << x << "  " << #y << " : " << y << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector <ll> vll;
typedef set <char> sch;
typedef set <ll> sll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e3 + 19;

ll n, x, y;

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	x = n * 800;
	y = ( n / 15 ) * 200;
	cout << x - y << endl;
	return 0;
}
