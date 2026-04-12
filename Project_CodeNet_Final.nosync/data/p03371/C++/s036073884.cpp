#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define MOD 1000000007
#define fi first
#define se second
#define ld double

using namespace std;

typedef long long ll;
typedef pair< int , int > PII;

ll a, b, c, x, y;

int main(){
    // ifstream cin("date.in");
    // ofstream cout("date.out");

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c >> x >> y;

    int mn = min(x, y);
    ll cost = min(a * mn + b * mn, c * mn * 2);

    x -= mn;
    y -= mn;

    cost += min(a * x + b * y, 2 * c * max(x, y));
    cout << cost;

	return 0;
} 