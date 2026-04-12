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


int main(int argc, char* argv[])
{
    int n,K;
    scanf("%d%d", &n, &K);

    ll ans=0;
    int b;
    for(b=K+1; b<=n; b++) {
        ll ans0=0;
        int p=n/b;
        int q=n%b;
        if(K<=q) {
            ans0=(ll)p*(b-q-1)+(ll)(p+1)*(q-K+1);
            if(K==0) ans0--;
        }
        else {
            ans0=(ll)p*(b-K);
        }
        ans+=ans0;
    }
    printf("%lld\n", ans);

    return 0;
}