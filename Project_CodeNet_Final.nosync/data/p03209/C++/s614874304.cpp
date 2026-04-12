#include <bits/stdc++.h>

using namespace std;

long long a(int n) {// レベルnバーガーの厚さ
    return (1LL << (n + 2)) - 3;
}

long long p(int n) {// レベルnバーガーに含まれるパティの枚数
    return (1LL << (n + 1)) - 1;
}

long long solve(int n, long long x) {
    if (n == 0) return 1;
    
    auto aa = a(n - 1);
    auto pp = p(n - 1);
    
    if (x == 1) return 0;
    else if (x <= aa + 1) return solve(n - 1, x - 1);
    else if (x == aa + 2) return pp + 1;
    else if (x <= (aa + 1) * 2) return pp + 1 + solve(n - 1, x - aa - 2);
    else return pp * 2 + 1;
}

int main() {
    int N;
    long long X;

    cin >> N >> X;
    cout << solve(N, X) << endl;
    return 0;
}
