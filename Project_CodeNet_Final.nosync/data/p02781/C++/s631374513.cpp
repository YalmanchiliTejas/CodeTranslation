#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

char s[105];
int n, dp[105][4][2], K;

int dfs(int num, int use, int limit) {
    int ans = 0;
    if(use > K) return 0;
    if(num > n) return use == K;
    if(dp[num][use][limit] != -1) return dp[num][use][limit];
    int up = limit?s[num]-'0':9;
    for(int i = 0; i <= up; ++i)
        ans += dfs(num+1, use+(i!=0), limit&&i==up);
    return dp[num][use][limit] = ans;
}

void run_case() {
    cin >> (s+1) >> K;
    n = strlen(s+1);
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 1);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}