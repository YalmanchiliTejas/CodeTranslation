#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <string>

#define REP(i, n) for (int i=0;i<(n);i++)
#define FOR(i, a, b) for (int i=(a);i<(b);i++)

using namespace std;
int A, B, C, X, Y;

int main()
{
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int ans = 0;
    if(2*C<A+B) {
        int tmp = min(X, Y);
        X -= tmp;
        Y -= tmp;
        ans += 2*C*tmp;
        if(X>0) {
            if(2*C<A) {
                ans += 2*C*X;
            } else {
                ans += A*X;
            }
        } else {
            if(2*C<B)
                ans += 2*C*Y;
            else
                ans += B*Y;
        }
    } else {
        ans += A*X + B*Y;
    }
    cout << ans << endl;


    return 0;
}
