//
// Created by munaiyi on 2020/3/18.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
char shit[maxn];
int nine[10];

inline long long Get(int num, int ci) {
    if (ci < 0) return 0;
    if (ci > num) return 0;
    long long ans = 1, cnt = 1;
    while (ci) {
        ans *= num;
        cnt *= ci;
        ci--;
        num--;
    }
    return ans / cnt;
}

int main() {
    nine[0] = 1;
    for (int i = 1; i < 5; i++) {
        nine[i] = nine[i - 1] * 9;
    }
    int nz = 0;
    scanf("%s%d", shit, &nz);
    int l = strlen(shit);
    shit[l++] = '0';
    long long ans = 0;
    for (int i = 0; i < l; i++) {
        if (shit[i] == '0') {
            continue;
        }
        ans += Get(l - 2 - i, nz) * nine[nz];
        ans += (shit[i] - '1') * Get(l - 2 - i, nz - 1) * nine[nz - 1];
        nz--;
        if (nz == 0) {
            ans++;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

