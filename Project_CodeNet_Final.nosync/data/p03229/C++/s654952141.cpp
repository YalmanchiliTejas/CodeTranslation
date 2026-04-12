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
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    vector<long> a(n);
    long i;
    for(i=0; i<n; i++) {
        scanf("%ld", &a[i]);
    }
    sort(a.begin(), a.end());

    ll ans=0;
    if(n%2==0) {
        long k = n/2;
        for(i=0; i<k; i++) {
            if(i==k-1) ans -= a[i];
            else       ans -= 2*a[i];
        }
        for(i=k; i<n; i++) {
            if(i==k)   ans += a[i];
            else       ans += 2*a[i];
        }
    }
    else {
        long k = n/2;
        ll ans0=0;
        for(i=0; i<k+1; i++) {
            if(i>=k-1) ans0 -= a[i];
            else       ans0 -= 2*a[i];
        }
        for(i=k+1; i<n; i++) {
            ans0 += 2*a[i];
        }

        ll ans1=0;
        for(i=0; i<k; i++) {
            ans1 -= 2*a[i];
        }
        for(i=k; i<n; i++) {
            if(i<=k+1) ans1 += a[i];
            else       ans1 += 2*a[i];
        }
        //printf("%lld %lld\n", ans0, ans1);
        ans = MAX(ans0, ans1);
    }

    printf("%lld\n", ans);

    return 0;
}
