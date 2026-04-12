#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;


char str[10005];
ll dp[2][100];   // (prev/curr), (mod dの値) という選び方の数（下位に制限なしのもののみ）

int main(int argc, char* argv[])
{
    int d;
    scanf("%s%d", str, &d);
    int n=strlen(str);

    int prev=0, curr=1;
    int i,k,m;
    int save=0;   // 制限ありのほうの現在のmod dの値
    for(i=1; i<=n; i++) {
        int cc=str[i-1]-'0';
        for(m=0; m<d; m++) {
            dp[curr][m]=0;
        }
        for(k=0; k<cc; k++) {
            dp[curr][(save+k)%d]++;
            dp[curr][(save+k)%d] %= MOD;
        }
        for(m=0; m<d; m++) {
            for(k=0; k<10; k++) {
                dp[curr][(m+k)%d]+=dp[prev][m];
                dp[curr][(m+k)%d] %= MOD;
            }
        }
        save = (save+cc)%d;
        swap(prev,curr);
    }

    ll ans = (dp[prev][0]-1+MOD)%MOD;
    if(save==0) ans++;
    printf("%lld\n", ans);

    return 0;
}
