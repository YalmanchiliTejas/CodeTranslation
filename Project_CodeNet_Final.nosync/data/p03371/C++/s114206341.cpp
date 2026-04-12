#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    int diff,same;
    int ans;

    if(max(X,Y) == X){
        diff = X - Y;
        same = Y;
        if(2 * C < A + B){
            ans = 2 * C * same;
        }else{
            ans = (A + B) * same;
        }

        if(2 * C < A){
            ans += 2 * C * diff; 
        }else{
            ans += A * diff;
        }
    }else{
        diff = Y - X; 
        same = X;
        if(2 * C < A + B){
            ans = 2 * C * same;
        }else{
            ans = (A + B) * same;
        }

        if(2 * C < B){
            ans += 2 * C * diff; 
        }else{
            ans += B * diff;
        }
    }

    
    cout << ans << endl;
}