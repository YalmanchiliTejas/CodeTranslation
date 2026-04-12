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
#include <stack>
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
//const long long MOD = 998244353;

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    vector<ll> a(n),b(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    ll mid=(n%2? a[n/2]*2: a[n/2-1]+a[n/2]);

    for(i=0; i<n; i++) {
        b[i]=abs(2*a[i]-mid);
    }
    sort(b.begin(),b.end());

    ll sum=0;
    for(i=0; i<n; i++) {
        if(i<2) sum+=b[i];
        else  sum+=b[i]*2;
    }
    printf("%lld\n", sum/2);


    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
