#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>
#include <map>
#include <stdio.h>
#include <cstring>
#include <queue>
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
char _;
using namespace std;

using ll = long long;
char arr[10001];
ll final = 0;
ll length = 0;
ll filler = 0;
unsigned long long int dp[10001][2][300];

ll calc(ll position, bool flag, ll sum)
{
    ll answer = 0;
    ll limit = 9;
    if (flag) limit = arr[position] - '0';
    if (position == length) {
        if (sum % filler == 0) return 1;
        else return 0;
    }

    if (dp[position][flag][sum] != -1) return dp[position][flag][sum];

    for (ll i = 0; i <= limit; i++) {
        if (i < limit || flag == false) {answer += calc(position + 1, false, (sum % filler) + i );  }
        else if (i == limit) {answer += calc(position + 1, true, (sum % filler) + i );}
    }
    return dp[position][flag][sum] = answer%1000000007;
}


int main(){
    cin>>arr;
    length = strlen(arr);
    gc(filler);
    memset(dp, -1, sizeof(dp));
    final = calc(0, true, 0);
    final --;
    if (final < 0) final = 1000000007  + final;
    else final = final % 1000000007;
    cout<<final<<"\n";
    return 0;
}