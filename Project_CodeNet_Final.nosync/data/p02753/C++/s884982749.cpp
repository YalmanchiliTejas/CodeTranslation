#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

char s[5];
int num[3];

int main() {
    scanf("%s", s + 1);
    rep(i, 1, 3) num[s[i] - 'A']++;
    if (!num[0] || !num[1]) puts("No");
    else puts("Yes");
    return 0;
}
