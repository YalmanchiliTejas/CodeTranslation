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
#define MOD 1000000007
using namespace std;

int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    vector<long> h(n);
    long i;
    long cnt=0;
    long m=0;
    for(i=0; i<n; i++) {
        scanf("%ld", &h[i]);
        if(m<=h[i]) cnt++;
        m = MAX(m, h[i]);
    }
    printf("%ld\n", cnt);
 
    return 0;
}
