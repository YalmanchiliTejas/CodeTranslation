#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B < 2*C) {
        cout << A * X + B * Y << endl;
    }
    else {
        if (X < Y) {
            int ans1 = 2 * Y*C;
            int ans2 = 2 * X*C + (Y - X)*B;
            cout<<min(ans1, ans2)<<endl;
        }
        else {
            int ans3 = 2 * X*C;
            int ans4 = 2 * Y*C + (X - Y)*A;
            cout<<min(ans3, ans4);
        }
    }
    return 0;
}
