#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    //case1
    ans = A * X + B * Y;
    //case2
    ans = min(ans, C * 2 * max(X, Y));
    //case3
    if(X > Y){
        ans = min(ans, C * 2 * min(X, Y) +A *abs(X-Y));
    }
    else{
        ans = min(ans, C * 2 * min(X, Y) + B * abs(X - Y));
    }    
    cout << ans << endl;
}
