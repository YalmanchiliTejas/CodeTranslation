#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    int piza = 0;

    if(A+B > 2 * C) {
        if(X >= Y) {
            piza += 2 * Y * C;
            if(A > 2 * C) {
                //cout << "reach pt0" << endl;
                piza += 2 * (X - Y) * C;
            } else {
                piza += A * (X - Y); 
                //cout << "reach pt1" << endl;
            }
        } else {
            piza += 2 * X * C;
            if(B > 2 * C) {
                piza += 2 * (Y - X) * C;
                //cout << "reach pt2" << endl;
            } else {
                piza += B * (Y - X);
                //cout << "reach pt3" << endl;
            }
        }
    } else {
        if(X >= Y) {
            piza += A * Y + B * Y;
            if(A > 2 * C) {
                piza += 2 * C * (X - Y);
                //cout << "reach pt4" << endl;
            } else {
                piza += A * (X - Y);
                //cout << "reach pt5" << endl;
            }
        } else {
            piza += A * X + B * X;
            if(B > 2 * C) {
                piza += 2 * C * (Y - X);
                //cout << "reach pt6" << endl;
            } else {
                piza += B * (Y - X);
                //cout << "reach pt7" << endl;
            }
        }
    }
    cout << piza << endl;
}