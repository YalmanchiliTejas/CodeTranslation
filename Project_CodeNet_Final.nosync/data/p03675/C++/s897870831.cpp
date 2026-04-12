#include<bits/stdc++.h>

using namespace std;
const int N = 200000 + 10;
typedef long long ll;
int b[N], pre[N], vis[N], a[N], mark[N];
vector<int> path[N];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        scanf("%d", &a[i]);
    int sb = n /2 + 1;
    if(n & 1)
    {
        b[sb] = a[1];
        sb++;
        for(int i = 2; i<=n; i+=2)
        {
            b[sb] = a[i];
            b[n - sb + 1] = a[i+1];
            sb ++;
        }
    }
    else
        for(int i = 1; i<=n; i+=2)
        {
            b[sb] = a[i];
            b[n - sb + 1] = a[i+1];
            sb ++;
        }
    for(int i = 1; i<=n; i++){
            if(i!=1)
            printf(" ");
        printf("%d", b[i]);
    }
    return 0;
}
