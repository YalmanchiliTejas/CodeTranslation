  #include<bits/stdc++.h>
  using namespace std;

  const int N = 1e5 + 10;
  const int mod = 1e9 + 7;

  vector<int> nums;
  int D;
  int dp[10010][110][2];
  int n;

  template<typename T>
  void add_self(T& a, T b)
  {
    a += b;
    if(a > mod)
    {
      a -= mod;
    }
  }


  int func(int i, int sum, bool pre)
  {
    if(i == n)
    {
      return sum == 0;
    }
    if(dp[i][sum][pre] != -1)
    {
      return dp[i][sum][pre];
    }
    int sol = 0;
    if(pre)
    {
      for(int d = 0; d <= nums[i]; d++)
      {
        add_self(sol, func(i + 1, (sum + d) % D , d == nums[i]));
      }
    }
    else
    {
      for(int d = 0; d <= 9; d++)
      {
        add_self(sol, func(i + 1, (sum + d ) % D, false));
      }
    }
    return dp[i][sum][pre] = sol;
  }



  int main()
  {
    string s;
    cin >> s;
    scanf("%d", &D);
    n = s.length();
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
      nums.push_back(s[i] - '0');
    }
    
    cout << func(0, 0, true) - 1;
    
    return 0;
  }
