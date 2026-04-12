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

char str[100005];
bool in[100005];
bool ans[100005];

int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);
    scanf("%s", str);

    long i;
    for(i=0; i<n; i++) {
        in[i]=(str[i]=='o'? 0: 1);
    }
    in[n]=in[0];
    in[n+1]=in[1];
    
    bool a0[4]={0,0,1,1};
    bool a1[4]={0,1,0,1};
    long k;
    for(k=0; k<4; k++) {
        ans[0]=a0[k];
        ans[1]=a1[k];
        long i;
        for(i=2; i<n+2; i++) {
            if(in[(i-1)%n]==ans[i-1]) ans[i]=ans[i-2];
            else                      ans[i]=!ans[i-2];
        }
        if(ans[0]==ans[n] && ans[1]==ans[n+1]) {
            for(i=0; i<n; i++) {
                if(ans[i]) {
                    printf("W");
                }
                else {
                    printf("S");
                }
            }
            printf("\n");
            return 0;  
        }
    }
    printf("-1\n");

    return 0;
}
