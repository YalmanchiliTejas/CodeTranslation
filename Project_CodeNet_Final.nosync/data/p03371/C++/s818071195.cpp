#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#pragma warning(disable:4996)

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long a, b, c, x, y;
    scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &x, &y);
    
    long p=MIN(x,y);
    ll sum = MIN(a,2*c)*(x-p) + MIN(b,2*c)*(y-p) + MIN(a+b,c*2)*p;
    printf("%lld\n", sum);

    return 0;
}
