#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C,X,Y;
    long long ans = 0;
    long long ans2 = 0;
    cin >> A >> B >> C >> X >> Y;

    if(A+B > 2*C){
        ans = 2*min(X,Y)*C;
        if(X > Y){
            ans += (X-Y)*A;
        }else{
            ans += (Y-X)*B;
        }
        ans2 = 2*max(X,Y)*C;
        ans = min(ans,ans2);
    }else{
        ans = A*X+B*Y;
    }
    cout << ans << endl;
    return 0;
}
