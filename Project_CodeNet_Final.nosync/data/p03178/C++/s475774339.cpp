#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define mp make_pair
 
using namespace std;
 
typedef long long ll;

const int MOD = 1e9+7;
int dp[10005][105][2];
bool mark[10005][105][2];
int n, d;
char s[10005];

void add(int &a, int b) {
    a += b;
    if(a >= MOD) a-= MOD;
}

int f(int i, int j, bool lim) {
    if(i == n) return j == 0;
    if(mark[i][j][lim]) return dp[i][j][lim];
    mark[i][j][lim] = true;
    int ret = 0;
    int up = lim ? s[i] - '0' : 9;    
    for(int k = 0; k <= up; k++) {
        int newJ = (j+k)%d;
        add(ret, f(i+1, newJ, lim&(k==up)));
    }

    return dp[i][j][lim] = ret;
}

int main() {
    ll k;
	scanf(" %s %d", s, &d);
    n = strlen(s);
  	int ans = f(0,0,1) - 1;
  	if(ans < 0) ans += MOD;
    printf("%d\n", ans);
	
    return 0;
}