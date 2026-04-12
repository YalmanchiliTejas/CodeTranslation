#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[110][2][4];
int seen[110][2][4];
string digit;
int k;

int solve(int id, int can, int cnt)
{
    if(cnt > k) return 0;
    if(id == digit.size())
        return cnt == k;
    if(seen[id][can][cnt]) return dp[id][can][cnt];
    int num = digit[id] - '0';
    int ans = 0;
    for(int i = 0; i < 10; i++)
        if(can or i <= num)
            ans += solve(id + 1, can or i < num, cnt + (i > 0));
    seen[id][can][cnt] = true;
    return dp[id][can][cnt] = ans;
}

int32_t main()
{
    cin >> digit >> k;
    cout << solve(0, 0, 0) << '\n';
  
	return 0;
}