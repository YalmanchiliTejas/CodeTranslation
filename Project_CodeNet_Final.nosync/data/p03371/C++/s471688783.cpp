#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll sum = 0;
    ll x,y;
    for(ll i = 0; i <= max(2*X,2*Y);i++)
    {
        x = X - i / 2;
        y = Y - i / 2;
        if(X - i / 2 <= 0)
        {
            x = 0;
        }
        if(Y - i / 2 <= 0)
        {
            y = 0;
        }
        if(sum == 0)
        {
            sum = x*A + y*B + i*C;
            continue;
        }
        sum = min(sum, x*A + y*B + i*C);
    }
    cout << sum << endl;
    return 0;
}
