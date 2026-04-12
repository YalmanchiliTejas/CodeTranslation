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
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long x,y,z;
    scanf("%ld%ld%ld", &x,&y,&z);

    printf("%ld\n", (x-z)/(y+z));
 
    return 0;
}
