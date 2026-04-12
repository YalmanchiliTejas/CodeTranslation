#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y;
    int ans;

    cin >> A >> B >> C >> X >> Y;

    int ans1 = max(X,Y)*2*C;
    int ans2 = (X > Y) ? min(X,Y)*2*C + (X-min(X,Y))*A : min(X,Y)*2*C + (Y-min(X,Y))*B;
    int ans3 = A*X + B*Y;

    ans = min(ans1,min(ans2,ans3));

    cout << ans << endl;
    return 0;

} 
