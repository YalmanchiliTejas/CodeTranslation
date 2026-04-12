#include <bits/stdc++.h>
using namespace std;

// const long long int MOD = 1000000007;
const int MOD = 1000000007;


int main() {
    long long int A,B,C,X,Y,p,q,r;
    cin >> A >> B >> C >> X >> Y;
    if (A+B > 2*C) {
        if (min(X,Y)==Y && A>2*C) {
            r = 2*X;
            p = 0;
            q = 0;
        }
        else if (min(X,Y)==Y && A<=2*C) {
            r = 2*Y;
            p = X-Y;
            q = 0;
        }
        else if (min(X,Y)==X && B>2*C) {
            r = 2*Y;
            p = 0;
            q = 0;
        }
        else if (min(X,Y)==X && B<=2*C) {
            r = 2*X;
            q = Y-X;
            p = 0;
        }
    }
    else {
        p=X;
        q=Y;
        r=0;
    }
    cout << A*p + B*q + C*r << endl;
}