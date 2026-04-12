#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 * 2 + 10;
typedef long long ll;

ll st[N];
int vis[N];

int main()
{
    ll n,a,p;
    cin >> n >> a >> p;
    memset(vis,-1,sizeof vis);
    int i = 0;
    ll j = a;
    // 找到环的入口
    for(i = 0, j = a; vis[j] == -1; i ++, j = j * j % p)
        vis[j] = i,st[i] = j;
    ll ans = 0,sum = 0;
    // 表示无环
    if(n == vis[j])
    {
        for(int k = 0; k < n; k ++) ans += st[k];
        cout << ans << endl;
        return 0;
    }
    
    // 环的前驱
    for(int k = 0; k < vis[j]; k ++) ans += st[k];
    
    // 环的后继
    for(int k = 0; k < (n - vis[j]) % (i - vis[j]); k ++) ans += st[k + vis[j]];

    // 环的内部
    for(int k = vis[j]; k < i; k ++) sum += st[k];
    
    cout << ans + ((n - vis[j]) / (i - vis[j]) * sum);
    
}