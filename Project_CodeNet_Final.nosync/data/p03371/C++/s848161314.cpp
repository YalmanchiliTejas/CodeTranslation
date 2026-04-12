#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C,X,Y,ans;
    cin >> A >> B >> C >> X >> Y; //ABC値段　XY要求
    if (X<Y) {
        if (A*X + B*Y < C*2*X +B*(Y-X)) {
            ans = A*X +B*Y;
        } else if (B*(Y-X) < C*2*(Y-X)) {
            ans = C*2*X +B*(Y-X);
        } else {
            ans = C*2*Y;
        }
    } else {
        if (A*X + B*Y < C*2*Y +A*(X-Y)) {
            ans = A*X +B*Y;
        } else if (A*(X-Y) < C*2*(X-Y)){
            ans = C*2*Y +A*(X-Y);
        } else {
            ans = C*2*X;
        }
    }
    cout << ans;
}