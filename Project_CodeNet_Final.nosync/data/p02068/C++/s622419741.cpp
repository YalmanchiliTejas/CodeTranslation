#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

template <typename Tp>
inline void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

const int N = 1e3 + 7;

int Cnt;
std::map<int, int> Mp;
std::vector<long long> V;

int main() {
    int n;
    read(n);
    for (int i = 1; i <= n; ++i) {
        int x;
        read(x);
        int Cur = x;
        for (int j = 2; j * j <= Cur; ++j) {
            if (Cur % j) continue;
            if (Mp.find(j) == Mp.end()) {
                Mp[j] = ++Cnt;
                V.push_back(x);
            }
            else V[Mp[j] - 1] += x;
            while (Cur % j == 0) Cur /= j;
        }
        if (Cur > 1) {
            if (Mp.find(Cur) == Mp.end()) {
                Mp[Cur] = ++Cnt;
                V.push_back(x);
            }
            else V[Mp[Cur] - 1] += x;
        }
    }
    long long Ans = 0;
    for (int i = 0; i < (int)V.size(); ++i) Ans = std::max(Ans, V[i]);
    printf("%lld\n", Ans);
    return 0;
}
