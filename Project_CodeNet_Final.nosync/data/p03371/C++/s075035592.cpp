#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int A,B,C,X,Y;

// A+B <= 2C
void solve1(){
    int ans = A*X + B*Y;
    cout << ans << endl;
    return;
}

// A + B > 2C
void solve2() {
    int ans = 0;
    int c_cnt = X < Y ? 2*X : 2*Y; //C を買う数
    ans += C*c_cnt;
    if (X < Y) {
        if (C*2*(Y-X) < (Y-X)*B ) ans += 2*C*(Y - X);
        else ans += B*(Y-X);
    } else {
        if (C*2*(X-Y) < (X-Y)*A) ans += 2*C*(X - Y);
        else ans += A*(X-Y);
    }
    cout << ans << endl;
    return;
}

int main(){
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    if (A+B <= 2*C) solve1();
    else solve2();
    return 0;
}
