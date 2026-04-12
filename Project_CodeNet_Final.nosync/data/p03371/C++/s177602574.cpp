#include<iostream>

using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long ans = 0;
    if(A+B >= 2*C){
        ans = min(X, Y)*2*C;
    }
    else ans = min(X, Y)*(A+B);

    if(X > Y){
        if(A > 2*C)ans += 2*C*(X -Y);
        else ans += A*(X - Y);
    }
    else if(Y > X){
        if(B > 2*C)ans += 2*C*(Y - X);
        else ans += B*(Y - X);
    }
    else ans = ans;
    cout << ans;
}