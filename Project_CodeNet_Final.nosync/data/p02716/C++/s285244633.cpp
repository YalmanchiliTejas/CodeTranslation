#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
const int maxn = 200009;
int n,a[maxn];
ll f[maxn][2][3];
int main(){
    scanf("%d",&n);
    for(int i = 0; i <= n; i++){
        f[i][0][0] = f[i][0][1] = f[i][0][2] = f[i][1][0] = f[i][1][1] = f[i][1][2] = -1e17;
    }
    f[0][0][0] = 0;
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++){
        f[i][0][0] = f[i-1][1][0];
        f[i][0][1] = max(f[i-1][0][0],f[i-1][1][1]);
        f[i][0][2] = max(f[i-1][0][1],f[i-1][1][2]);
        f[i][1][0] = f[i-1][0][0] + a[i];
        f[i][1][1] = f[i-1][0][1] + a[i];
        f[i][1][2] = f[i-1][0][2] + a[i];
    }
    if(n % 2 == 0) printf("%lld",max(f[n-1][1][0],f[n][1][1]));
    else printf("%lld",max(max(f[n-2][1][0],f[n-1][1][1]),f[n][1][2]));
    return 0;
}