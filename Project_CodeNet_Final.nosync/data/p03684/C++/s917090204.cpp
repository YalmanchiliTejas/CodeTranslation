#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#define lson l, mid, i<<1
#define rson mid+1, r, i<<1|1
#define PII pair<int, int>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
//const auto INF  = 0x3f3f3f3f;
const int N = 1e5+5;

struct node {
    int x, y;
    int id1, id2, id;
}maps[N], ans[N*2];

bool cmp1(const struct node &u, const struct node &v) {
    return u.x < v.x;
}

bool cmp2(const struct node &u, const struct node &v) {
    return u.y < v.y;
}

bool cmp3(const struct node &u, const struct node &v) {
    return u.x < v.x;
}

int pre[N];

int find(int x) {
    int r, i, j;
    r = x;
    while(pre[r] != r) {
        r = pre[r];
    }
    i = x;
    while(pre[i] != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

bool mx(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) {
        pre[fx] = fy;
        return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &maps[i].x, &maps[i].y);
        maps[i].id = i;
        pre[i] = i;
    }
    sort(maps+1, maps+1+n, cmp1);
    int cnt = 0;
    for(int i=2; i<=n; i++) {
        ans[++cnt].x = maps[i].x - maps[i-1].x;
        ans[cnt].id1 = maps[i].id;
        ans[cnt].id2 = maps[i-1].id;
    }
    sort(maps+1, maps+1+n, cmp2);
    for(int i=2; i<=n; i++) {
        ans[++cnt].x = maps[i].y - maps[i-1].y;
        ans[cnt].id1 = maps[i].id;
        ans[cnt].id2 = maps[i-1].id;
    }
    sort(ans+1, ans+1+cnt, cmp3);
    int k = 0;
    LL answer = 0;
    for(int i=1; i<=cnt; i++) {
        if(mx(ans[i].id1, ans[i].id2)) {
            k++;
            answer += ans[i].x;
            if(k == n-1)
                break;
        }
    }
    
    printf("%lld\n", answer);
}









