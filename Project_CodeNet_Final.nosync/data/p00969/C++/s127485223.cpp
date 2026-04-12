#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 7;

int n, a[MAXN], ans;
set<int> stk;

int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        stk.insert(a[i]);
    }
    //cout << n << endl;
    sort(a+1, a+n+1);
    ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            if(n-j+2 <= ans) break;
            //if(vis[i] && vis[j]) continue;
            int val = a[j] - a[i];
            int num = 2, tmp = a[j] + val;
            //vis[i] = vis[j] = 1;
            while(tmp <= a[n]) {
                if(stk.count(tmp)) num++, tmp += val;
                else break;
            }
            ans = max(ans, num);
            if(ans == n-i+1) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
