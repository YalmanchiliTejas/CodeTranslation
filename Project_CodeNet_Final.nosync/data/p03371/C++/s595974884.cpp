#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    for(int z = 0; z/2 <= max(X,Y);z++)
    {
        int a = max(0,X - z/2);
        int b = max(0,Y - z/2);
        int sum = A*a + B*b +C*z;
        if(ans == 0) ans = sum;
        else ans = min(ans,sum);
    }
    cout << ans << endl;
}
