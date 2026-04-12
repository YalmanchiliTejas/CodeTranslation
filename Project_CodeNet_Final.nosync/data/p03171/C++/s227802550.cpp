
// ~/SolverToBe/Developers/Corvus
// ~/sudo apt-get verdict Accpeted

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 3005, M = 1000005;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;

int n,a[N];
ll dp[2][N][N];

ll calc(int p, int i,int j) {
    if(i > j)
        return 0;
    ll &r = dp[p][i][j];
    if(r!=-2e18)
        return r;
    if(p==0) 
        r = max(calc(p^1, i+1, j) + a[i], calc(p^1, i, j-1) + a[j]);
    else
        r = min(calc(p^1, i+1, j) - a[i], calc(p^1, i, j-1) - a[j]); 
    return r;
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",a+i);
    for(int i=0; i<2; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                dp[i][j][k] = -2e18;
    printf("%lld\n", calc(0,0,n-1));
    return 0;
}