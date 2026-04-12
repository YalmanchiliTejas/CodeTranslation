#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = A * X + B * Y;

    ll b = C * X * 2;
    if(X < Y) b += B * (Y - X);

    ans = min(ans, b);

    ll c = C * Y * 2;
    if(X > Y) c += A * (X - Y);

    ans = min(ans, c);

    cout << ans << endl;
}