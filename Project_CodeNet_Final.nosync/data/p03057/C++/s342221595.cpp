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

char str[200005];

// A(Bを数個)A(Bを数個)..A(Bを数個) 
// という列の作り方が何通りあるか、を求める
// ただし列の長さをn、Bを重ねるのは各箇所について0個以上k個以下とする
// また両端がつながっているものとする。
ll func( int n, int k)
{
    if(k>=n) k=n-1;

#ifdef _DEBUG
    printf("%d %d\n", n, k);
#endif
    vector<ll> dp(n+1);   // dp[i]: func(i,k)と同じ。ただし両端がつながっていなくてAから始まるものとする。
    vector<ll> sdp(n+2);  // dpの累積和
    dp[0]=1;
    sdp[0]=0; sdp[1]=1;
    int i;
    for(i=1; i<=n; i++) {
        dp[i]=(sdp[i]-sdp[MAX(0,i-k-1)]+MOD)%MOD;
        sdp[i+1]=(sdp[i]+dp[i])%MOD;
    }
    ll ans = dp[n];

    // dp[n]は、Aから始まるものだけを数えたもの。
    // 両端がつながっている状況で、Bから始まるものを数える
    // Bが最初にp個重なった場合を考えて足し合わせればよい
    int p;
    for(p=1; p<=k; p++) {
        // dp[n-p-1],dp[n-p-2],..という(k-p+1)個を足し合わせればよい
        ans = (ans + sdp[n-p] - sdp[n-k-1] +MOD)%MOD;
    }

    return ans;
}

int main(int argc, char* argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str);

    char c=str[0];
    int min_odd=INF-1;
    int cnt_first=-1;
    int cnt=0;
    int cnt2=0;
    int i;
    for(i=0; i<m; i++) {
        if(str[i]==c) {
            cnt++;
        }
        else {
            if(cnt>0) {
                if(cnt_first<0) cnt_first=cnt;
                if(cnt%2) min_odd = MIN(min_odd, cnt);
                cnt=0;
            }
            cnt2++;
        }        
    }

    if(cnt2==0) {
        printf("%lld\n", func(n, 1));
    }
    else {
        if(n%2==0) {
            int k = (cnt_first%2==0? cnt_first+1: cnt_first);
            if(min_odd>0) k = MIN(k, min_odd);
            printf("%lld\n", func(n/2, (k-1)/2) *2 %MOD);
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}

