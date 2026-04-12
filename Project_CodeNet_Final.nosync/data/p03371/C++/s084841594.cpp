#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
    
    int ans = 0;
    int cheaper_price = A + B < 2*C ? A + B : 2*C;
    while(X > 0 && Y > 0){
        X--; Y--;
        ans += cheaper_price; 
    }
    
    if (X > 0) {
        cheaper_price = A < 2*C ? A : 2*C;
        for (; X > 0; X--) ans += cheaper_price;
    } else if (Y > 0) {
        cheaper_price = B < 2*C ? B : 2*C;
        for (; Y > 0; Y--) ans += cheaper_price;
    }

    cout << ans << endl;
}