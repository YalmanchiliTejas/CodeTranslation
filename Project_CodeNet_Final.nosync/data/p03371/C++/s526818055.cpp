#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int A,B,C,X,Y,p1,p2,p3,t;
    cin >> A >> B >> C >> X >> Y;

    p1 = A*X+B*Y;
    p2 = C*max(X,Y)*2;

    t = min(X,Y);
    p3 = C*t*2+(max(X,Y)-t)*((X>Y) ? A : B);

    cout << min(p1, min(p2, p3)) << endl;
}