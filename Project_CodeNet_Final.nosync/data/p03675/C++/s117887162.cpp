#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
int a[maxn];
int main() {
    //freopen(".in", "r", stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n%2==0)
    {
        for(int i=n;i>=2;i-=2) printf("%d ",a[i]);
        for(int i=1;i<=n-1;i+=2) printf("%d ",a[i]);
    }
    else
    {
        for(int i=n;i>=1;i-=2) printf("%d ",a[i]);
        for(int i=2;i<=n-1;i+=2) printf("%d ",a[i]);
    }
    return 0;
}

