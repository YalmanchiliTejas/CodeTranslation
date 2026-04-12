#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans;
    if(X>=Y){
        ans=min(A*X+B*Y,Y*2*C+(X-Y)*A);
        ans=min(ans,X*C*2);
    }
    else{
        ans=min(A*X+B*Y,X*2*C+(Y-X)*B);
        ans=min(ans,Y*2*C);
    }
    cout << ans << endl;
}