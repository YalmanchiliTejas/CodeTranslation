#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans;
    if(A + B > 2 * C)
    {
        if(X > Y)
        {
            ans = min( 2*C * max(X,Y), 2 * C * Y + A * (X - Y));
        }
        else
        {
            ans = min( 2*C * max(X,Y), 2 * C * X + B * (Y - X));
        }
    }
    else
    {
        ans = A * X + B * Y;
    }
    cout << ans << endl;
}