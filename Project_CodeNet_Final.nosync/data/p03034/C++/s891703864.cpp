#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1e5 + 10;
int s[maxn], vis[maxn], n;

int main(){
    scanf("%d", &n);
    long long total = 0;
    for(int i = 0; i < n; i++){scanf("%d", &s[i]);}
    for(int c = 1; c < n; c++){
        int k = 0;
        long long ans = 0;
        memset(vis, 0, sizeof(vis));
        while(k * c < n - 1){// a + k * c == n - 1
            int next = (n - 1) - (k * c);
            if(next <= 0 || (next - c <= 0)){break;}
            if(vis[next]){break;}
            vis[next] = 1;
            ans += s[next];
            if(vis[k * c]){break;}
            vis[k * c] = 1;
            ans += s[k * c];
            total = max(total, ans);
            k++;
        }
    }
    printf("%lld", total);
    return 0;
}
