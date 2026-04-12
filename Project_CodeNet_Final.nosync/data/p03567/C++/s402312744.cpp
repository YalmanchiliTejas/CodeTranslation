#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100;
char s[maxn];
int len;
bool flag = false;

int main() {
#ifdef __AiR_H
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s", s); len = strlen(s);
//    printf("%s\n", s);
    for (int i = 0; i < len - 1; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            flag = true; break;
        }
    }
    if (flag) { printf("Yes\n"); }
    else { printf("No\n"); }
    return 0;
}
