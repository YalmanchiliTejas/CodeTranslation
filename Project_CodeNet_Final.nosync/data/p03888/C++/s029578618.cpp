#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    double R1, R2;
    scanf("%lf %lf", &R1, &R2);
    
    // 2. 出力.
    printf("%.10f\n", (R1 * R2) / (R1 + R2));
    return 0;
    
}