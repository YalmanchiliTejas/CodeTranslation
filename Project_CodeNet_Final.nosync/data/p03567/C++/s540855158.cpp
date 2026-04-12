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
//const long long MOD = 1000000007;
const long long MOD = 998244353;
using namespace std;


int main(int argc, char* argv[])
{
    char str[6]={0};
    scanf("%s", str);
    int i;
    for(i=0; i<5; i++) {
        if(str[i]=='A' && str[i+1]=='C') {
            printf("Yes\n"); return 0;
        }
    }
    printf("No\n");
    return 0;
}
