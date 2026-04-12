#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    ll ans1 = A*X + B*Y;
    ll ans2 = (X > Y) ? X*2*C : Y*2*C;
    ans1 = min(ans1, ans2);
    if (X == Y) {
        ans = ans1;
    }
    else {
        if (X > Y) {
            ll dif = X - Y;
            ans = dif * A + (Y*2*C);
        }
        else {
            ll dif = Y - X;
            ans = dif * B + (X*2*C);
        }
        ans = min(ans1, ans);
    }
    cout << ans << endl;
 
    




}
