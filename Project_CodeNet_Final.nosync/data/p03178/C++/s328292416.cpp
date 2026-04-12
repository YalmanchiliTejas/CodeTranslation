#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define MOD 1000000007
using namespace std;

ll dp[10005][100];

int main(int argc, char* argv[])
{
    char str[10005]={0};
    scanf("%s", str);
    long d;
    scanf("%ld", &d);

    long len=strlen(str);
    
    long i, j, m;
    dp[0][0]=1;
    for(i=1; i<len; i++) {
        for(j=0; j<=9; j++) {
            for(m=0; m<d; m++) {
                dp[i][m] = (dp[i][m]+dp[i-1][(m+j*d-j)%d]) %MOD;
            }
        }
    }

    ll ans = 0;
    long sum = 0;
    for(i=0; i<len; i++) {
        long curr = str[i]-'0';        
        for(j=0; j<(i==len-1? curr+1: curr); j++) {
            ans = (ans + dp[len-i-1][(11*d-sum-j)%d])%MOD;
        }
        sum = (sum+curr)%d;
    }

    printf("%lld\n", (ans+MOD-1)%MOD);

    return 0;
}
