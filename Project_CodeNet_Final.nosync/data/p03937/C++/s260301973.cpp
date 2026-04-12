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

char str[10][10];

int main(int argc, char* argv[])
{
    int h,w;
    scanf("%d%d", &h, &w);
    int i,j;
    for(i=0; i<h; i++) {
        scanf("%s", &str[i]);
    }
    int cnt=0;
    for(i=0; i<h; i++) {
        for(j=0; j<w; j++) {
            if(str[i][j]=='#') {
                cnt++;
                if(i==0 && j==0) continue;
                int num=0;
                if(i>0 && str[i-1][j]=='#') num++;
                if(j>0 && str[i][j-1]=='#') num++;
                if(num!=1) {
                    printf("Impossible\n"); return 0;
                }
            }
        }
    }
    if(cnt==h+w-1) printf("Possible\n");
    else printf("Impossible\n");

    return 0;
}
