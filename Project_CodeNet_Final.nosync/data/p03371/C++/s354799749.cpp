#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    ll AB = 0;
    ll BA = 0;
    ll AAB = 0;
    ll BAB = 0;
    ll ans;
    AB = C * max(X,Y) * 2;
    BA = A * X + B * Y;
    if(X > Y)
    {
        AAB = C * Y * 2 + A * (X - Y);
        ans = min(AB,BA);
        ans = min(ans,AAB);
    }
    else
    {
        BAB = C * X * 2 + B * (Y - X);
        ans = min(AB,BA);
        ans = min(ans,BAB);
    }
    
    
    
    

    cout << ans << endl;
    return 0;
}