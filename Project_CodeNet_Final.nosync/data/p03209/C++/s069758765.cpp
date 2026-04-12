#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string>
#include <stack>
#include <stdlib.h>
#include <iomanip>
#include <queue>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mset(a, b) memset(a, b, sizeof(a))
#define LL long long
#define P pair<int, int>
#define PLL pair<LL, LL>
const int MAX = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;

LL n, x;
vector<LL> cnt_L;
vector<LL> cnt_P;
LL solve(LL x, LL n)
{
    if(x == 0)  return 0;
    if(x == cnt_L[n]){
        return cnt_P[n];
    }
    LL p = (cnt_L[n]+1) >> 1;
    if(x < p){
        return solve(x-1, n-1);
    }
    else if(x > p)
    {
        return cnt_P[n-1] + solve(x-p, n-1) + 1LL;
    }
    else{
        return cnt_P[n-1]+1;
    }
}
int main()
{
    cin >> n >> x;
    cnt_L.resize(n+1);
    cnt_P.resize(n+1);
    cnt_L[0] = 1;
    cnt_P[0] = 1;
    for(int i = 1; i <= n; i++){
        cnt_L[i] = cnt_L[i-1]*2 + 3;
        cnt_P[i] = cnt_P[i-1]*2 + 1;
    }
    cout  << solve(x, n) << endl;
    return 0;
}

