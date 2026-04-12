#include <bits/stdc++.h>
const int maxn = int(1e5) + 7;
int n, same[maxn];
struct Ans {
    bool data[maxn];
    bool & operator [] (int index) {
        return data[(index + n) % n];
    }
} S;
void gao(int cur, int other) {
    bool flag = true;
    if (S[cur]) flag = false;
    if (same[cur] ^ flag) S[cur * 2 - other] = S[other];
    else S[cur * 2 - other] = !S[other];
}
bool check(int cur) {
    bool flag = true;
    if (S[cur]) flag = false;
    if (same[cur] ^ flag) return S[cur - 1] == S[cur + 1];
    return S[cur - 1] ^ S[cur + 1];
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    char ch;
    for (int i = 0; i < n; i++) scanf(" %c", &ch), same[i] = ch == 'o';
    bool flag = false;
    for (int i = 0; i < 2 && (!flag); i++)
        for (int j = 0; j < 2 && (!flag); j++) {
            S[0] = bool(i), S[1] = bool(j);
            gao(0, 1);
            for (int cur = 1; cur < n - 2; cur++) gao(cur, cur - 1);
            if (check(n - 2) && check(n - 1)) flag = true;
        }
    if (flag) for (int i = 0; i < n; i++) printf("%c%s", S[i] ? 'S' : 'W', i == n - 1 ? "\n" : "");
    else puts("-1");
    return 0;
}