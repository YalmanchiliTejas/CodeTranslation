#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    ll A,B,C,X,Y;

    cin >> A >> B >> C >> X >> Y;
    ll minResult;
    if(A+B > C+C)
    {
        ll minval = min(X,Y);
        ll maxval = max(X,Y);
        if(X < Y)
        {
            minResult = (C+C) * minval + B * (Y - X);
        }else{
            minResult = (C+C) * minval + A * (X - Y);
        }
        for(ll i = min(X,Y); i <= max(X,Y); ++i)
        {
            if(X < Y)
            {
                minResult = min(minResult,(C+C) * i  + B * (Y - i));
            }else
            {
                minResult = min(minResult,(C+C)*i + A * (X - i));
            }
            
        }
        cout << minResult << endl;
    }else{
        cout <<  A * X + B * Y << endl;
    }


	return 0;
}