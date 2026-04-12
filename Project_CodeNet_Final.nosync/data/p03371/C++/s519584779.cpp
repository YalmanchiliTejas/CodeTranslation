#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INFINITO 1000000000
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


int main() {

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = c * 2 * max(x, y);
    ans = min(ans, a * x + b * y);
    
    if ( x > y ) ans = min(ans, c * 2 * y + a * (x - y));
    else ans = min(ans, c * 2 * x + b * (y - x));

    cout << ans << endl;

    return 0;
}