#include<bits/stdc++.h>
using namespace std;
static const int INFTY = (1 << 21);
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if(A + B <= 2 * C){
        cout << A * X + B * Y << endl;
    }
    else{
        if(X > Y){
            cout << min(2 * C * Y + (X - Y) * A, 2 * C * Y + (X - Y) * 2 * C) << endl;
        }
        else{
            cout << min(2 * C * X + (Y - X) * B, 2 * C * X + (Y - X) * 2 * C) << endl;
        }
    }
    return 0;
}