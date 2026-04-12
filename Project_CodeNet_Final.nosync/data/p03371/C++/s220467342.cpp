#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,X,Y,ans;
    cin >> A >> B >> C >> X >> Y;
    if(2*C >= A + B) ans = A*X + B*Y;
    else if(X >= Y){
        if(2*C >= A) ans = 2*C*Y + A*(X - Y);
        else  ans = 2*C*X;
    }else if (X < Y){
        if(2*C >= B) ans = 2*C*X + B*(Y - X);
        else  ans = 2*C*Y;
    }
    cout << ans << endl;
    return 0;
}