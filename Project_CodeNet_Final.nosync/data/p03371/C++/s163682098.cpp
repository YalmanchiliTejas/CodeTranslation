#include        <bits/stdc++.h>
using   namespace       std;

int     main() {
        int A, B, C;
        int X, Y;
        cin >>A >>B >>C >>X >>Y;
        int S=X*A+B*Y;
        for (int i=0; i<=max(X, Y); i++) {
                int SS=i*C*2;
                SS += max(0, X-i)*A + max(0, Y-i)*B;
                S = min(S, SS);
        }
        cout <<S <<endl;
        return 0;
};