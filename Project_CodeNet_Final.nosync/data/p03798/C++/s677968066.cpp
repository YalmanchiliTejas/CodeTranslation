#include <bits/stdc++.h>
using namespace std;
char s[100005];
int ans[100005];
int main() {
    int n;
    scanf("%d%s", &n, s);
    for (ans[0] = 0; ans[0] < 2; ++ ans[0]) {
        for (ans[1] = 0; ans[1] < 2; ++ ans[1]) {
            for (int i = 2; i < n; ++ i)
                ans[i] = ans[i - 1] ^ ans[i - 2] ^ (s[i - 1] == 'x');
            if (ans[0] ^ ans[n - 2] ^ ans[n - 1] ^ (s[n - 1] == 'x')) continue;
            if (ans[1] ^ ans[n - 1] ^ ans[0] ^ (s[0] == 'x')) continue;
            for (int i = 0; i < n; ++ i) putchar("SW"[ans[i]]);
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}