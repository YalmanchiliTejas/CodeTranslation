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
    long n;
    scanf("%ld", &n);

    vector<long> count(26, INF);
    long i, j;
    for(i=0; i<n; i++) {
        long zz[26]={0};
        char str[51]={0};
        scanf("%s", str);
        for(j=0; j<strlen(str); j++) {
            zz[str[j]-'a'] ++;
        }
        for(j=0; j<26; j++) {
            count[j] = MIN(count[j], zz[j]);
        }
    }

    for(i=0; i<26; i++) {
        for(j=0; j<count[i]; j++) {
            printf("%c", i+'a');
        }
    }
    printf("\n");

    return 0;
}

