#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

string N;
int  k, sz;
vector<int> digits;
int cache[105][5][2];

void getDigits(string s)
{
      digits.clear();
      for(int i = 0; i < s.size(); i++)
      {
            int d = s[i] - '0';
            digits.push_back(d);
      }
}

int dp(int idx, int nonzero, int tight)
{
      if(nonzero > k) return 0;
      if(idx == sz)
      {
           return (nonzero ==k);
      }
      int &res = cache[idx][nonzero][tight];
      if(res != -1 )
            return res;

      res = 0;
      int limit = tight ? digits[idx] : 9;
      for(int i = 0; i <= limit; i++)
      {
            int newTight = (i == limit) ? tight : 0;
            res += dp(idx + 1, nonzero + (i != 0) , newTight);
      }
      return res;
}


int32_t main()
{
      IOS;
      cin >> N >> k;
      sz = N.size();
      memset(cache, -1, sizeof(cache));
      getDigits(N);
      int ans = dp(0, 0, 1);
      cout << ans;

      return 0;

}
