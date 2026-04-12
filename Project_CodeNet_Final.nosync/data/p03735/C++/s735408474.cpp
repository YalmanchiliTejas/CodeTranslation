#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, b, a) for(int i = (b); i >= (a); i--)
using namespace std;
const int N = 2e5 + 9, inf = 0x3f3f3f3f;
int n, l, r, cnt, sum, minn1 = inf, minn2 = inf, maxx1, maxx2, vis[N];
struct node{
    int num, pl;
}s[N << 1];
bool cmp(node x, node y){
    return x.num == y.num ? x.pl < y.pl : x.num < y.num;
}
int main(){
    scanf("%d", &n);
    rep(i, 1, n) {
        int x, y; scanf("%d%d", &x, &y);
        if(x > y) swap(x, y);
        minn1 = min(minn1, x), minn2 = min(minn2, y), maxx1 = max(maxx1, x), maxx2 = max(maxx2, y);
        s[++cnt].pl = i, s[cnt].num = x, s[++cnt].pl = i, s[cnt].num = y;
    }
    sort(s + 1, s + 2 * n + 1, cmp);
    l = 1;
    rep(i, 1, 2 * n) {
        if(!vis[s[i].pl]) sum++;
        vis[s[i].pl]++;
        if(sum == n) { r = i; break; }
    }
    int ans = s[r].num - s[l].num;
    while(r < n * 2){
        if(vis[s[l].pl] == 1) sum--;
        vis[s[l].pl]--, l++;
        if(sum != n) rep(i, r + 1, 2 * n) {
            vis[s[i].pl]++;
            if(vis[s[i].pl] == 1) {
                sum++, r = i;
                break;
            }
        }
        if(sum != n) break;
        ans = min(ans, s[r].num - s[l].num);
        //cout << l << " " << ans << endl;
    }
    //cout << ans << endl;
    printf("%lld", min(1ll * ans * (maxx2 - minn1), 1ll * (maxx1 - minn1) * (maxx2 - minn2)));
    return 0;
}