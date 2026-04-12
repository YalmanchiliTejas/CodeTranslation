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
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223372036854775807
#define INF 2147483647
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long r,g,b;
    scanf("%ld%ld%ld", &r, &g, &b);

    if((r*100+g*10+b)%4==0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
