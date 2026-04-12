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
    long n,k;
    char str[16]={0};
    scanf("%ld", &n);
    scanf("%s", str);
    scanf("%ld", &k);

    long i;
    for(i=0; i<n; i++) {
        if(str[i]!=str[k-1]) {
            str[i]='*';
        }
    }
    printf("%s\n", str);

    return 0;
}
