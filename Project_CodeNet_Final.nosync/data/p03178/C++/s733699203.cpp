#include <iostream>
#include <string>
#define SIZE 10005
#define MAX  105
  const int mod = (int)1e9 + 7;
  std::string s;
  int k, dp[SIZE][2][MAX];

  inline int add(int a, int b, int mod) {a += b; return a >= mod ? a - mod : a;}

  int digit_dp(int pos, int small, int d) {
    if(pos == s.length()) return d == 0;

    int& ans = dp[pos][small][d];
    if(ans!=-1) return ans;

    ans=0;
    int mx=9;
    if(!small) mx = s[pos]-'0';
    for(int i=0; i<=mx; i++) {
        int nsmall = small;
        if(i < mx) nsmall=1;
        ans = add(ans, digit_dp(pos+1, nsmall, (d+i)%k), mod);
    }

    return ans;
  }

  int main(void) {
    std::cin >> s >> k;
    for(int i=0; i<SIZE; i++) for(int j=0; j<2; j++) for(int l=0; l<MAX; l++) dp[i][j][l] = -1;

    printf("%d", add(digit_dp(0,0,0), mod-1, mod));
    return 0;
  }





