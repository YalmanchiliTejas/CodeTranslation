#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100+10;

char s[maxn];
ll f[maxn][5];

ll dp(int pos, int sta, bool lim) {
    if(sta<0)
        return 0;
    if(pos==0) {
        if(sta==0)
            return 1;
        else
            return 0;
    }
    if(!lim && f[pos][sta]>=0)
        return f[pos][sta];
    int up = 9;
    if(lim)
        up = s[pos]-'0';
    ll res = 0;
    for(int i=0; i<=up; i++) {
        if(i)
            res += dp(pos-1, sta-1, lim && i==up);
        else
            res += dp(pos-1, sta, lim && i==up);
    }
    if(!lim)
        f[pos][sta] = res;
    return res;
}

int main() {
    scanf("%s", s+1);
    int len = strlen(s+1);
    for(int i=1; i<=len/2; i++)
        swap(s[i], s[len-i+1]);
    int k;
    scanf("%d", &k);
    memset(f, -1, sizeof(f));
    printf("%lld\n", dp(strlen(s+1), k, true));
    return 0;
}
