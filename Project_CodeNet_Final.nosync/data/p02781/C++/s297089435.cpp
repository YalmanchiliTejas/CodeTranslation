#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
char ss[105];
int K;
ll solve1(char *s){
    ll res = 0;
    int n = strlen(s);
    res += 9ll * (n - 1);
    res += s[0] - '0';
    return res;
}
ll solve2(char *s){
    ll ans = 0;
    int n = strlen(s);
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ans += 81ll;
    // 开头还挺小
    for (int i = 1; i < s[0] - '0'; ++i)
        for (int j = 1; j < n; ++j)
            ans += 9ll;
    // 开头定下
    int t = 1;
    while (t < n && s[t] == '0')
        ++t;
    if (t < n)
        ans += solve1(s + t);
    return ans;
}
ll solve3(char *s){
    ll ans = 0;
    int n = strlen(s);
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                ans += 729ll;
    // 开头还挺小
    for (int i = 1; i < s[0] - '0'; ++i)
        for (int j = 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                ans += 81ll;
    // 开头不变了
    int t = 1;
    while (t < n && s[t] == '0')
        ++t;
    if (t < n){
        ans += solve2(s + t);
    }
    return ans;
}
void init(){
    scanf("%s", ss);
    assert(ss[0] != '0');
    K = read();
}
void solve(){
    ll ans = 0;
    if (K == 1) ans = solve1(ss);
    if (K == 2) ans = solve2(ss);
    if (K == 3) ans = solve3(ss);
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}