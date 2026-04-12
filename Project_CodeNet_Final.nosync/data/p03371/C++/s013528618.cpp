#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C; cin >> A >> B >> C;
    int X, Y; cin >> X >> Y;
    if(Y>X) {
        swap(X, Y);
        swap(A, B);
    }

    if(A > 2*C){
        cout << C * X * 2 << endl;
    } else if((A+B)/2.0 >= C ){
        cout << C * Y * 2 + A * (X-Y) << endl;
    } else {
        cout << A * X + B * Y << endl;
    }
}