#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull l[51] = {1}, p[51] = {1};  // l-0 버거의 길이 1, 패티 수 1

ull solution(ull n, ull x) {
    if (n == 1) {
        int base[6] = {0, 0, 1, 2, 3, 3};
        return base[x];
    } else {
        ull mid = l[n] / 2 + 1;  // 길이는 항상 홀수이다
        if (x < mid) {
            return solution(n - 1, x - 1);
        } else if (x == mid) {
            return p[n - 1] + 1;
        } else if (x > mid) {
            if (x == l[n]) {
                return 2 * p[n - 1] + 1;
            } else {
                return p[n - 1] + 1 + solution(n - 1, x - 1 - l[n - 1] - 1);
            }
        }
    }
    return -1;
}

int main() {
    ull n, x;
    cin >> n >> x;
    
    for (int i = 1; i <= 50; i++) {
        l[i] = 3 + 2 * l[i - 1];
        p[i] = 1 + 2 * p[i - 1];
    }
    
    cout << solution(n, x) << '\n';
    
    return 0;
}
