#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

    int ans = 0, ans_a = 0, ans_b = 0, ans_c = 0;
    
    ans_a = max(x, y) * 2 * c;

    ans_b = a * x + b * y;
    
    int p = x < y ? b : a;
    ans_c = min(x, y) * 2 * c + p * abs(x - y);
    
    ans = min({ans_a, ans_b, ans_c});
    printf("%d\n", ans);
}