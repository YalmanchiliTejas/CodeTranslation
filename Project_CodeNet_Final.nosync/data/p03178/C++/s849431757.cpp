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

char str[100005];
ll dp[100005][2][101];      // keta,smaller,amari

int main(int argc, char* argv[])
{
    int D;
    scanf("%s", str);
    scanf("%d", &D);

    int len=strlen(str);

    dp[0][0][0]=1;
    int i,j,k,m;
    for(i=0; i<len; i++) {
        int tmp=str[i]-'0';
        for(j=0; j<2; j++) {
            for(k=0; k<=(j? 9: tmp); k++) {
                for(m=0; m<D; m++) {
                    dp[i+1][j || k<tmp][(m+k)%D] += dp[i][j][m];
                    dp[i+1][j || k<tmp][(m+k)%D] %= MOD;
                }
            }
        }
    }
    printf("%lld\n", (dp[len][1][0]+dp[len][0][0]-1+MOD)%MOD);

    return 0;
}
