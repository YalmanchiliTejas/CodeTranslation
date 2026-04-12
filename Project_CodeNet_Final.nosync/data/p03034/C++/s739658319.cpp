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


int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    vector<ll> s(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld", &s[i]);
    }

    ll ans=0;   // A=n-1

    for(i=1; i<=(n-1)/2; i++) {
        ll sum=0;
        int curr0=0, curr1=n-1;
        int k;
        for(k=1; k<=(n-1)/i; k++) {
            int curr0_prev = curr0;
            curr0 = curr0 + i;
            curr1 = curr1 - i;
            if(curr0_prev==curr1 || curr0==curr1 || curr1<=i) {
                break;
            }
            sum+=s[curr0]+s[curr1];
            ans = MAX(ans, sum);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
