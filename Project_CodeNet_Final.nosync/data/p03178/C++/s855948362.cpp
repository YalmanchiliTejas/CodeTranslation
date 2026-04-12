  //Keep Working Hard
  // I__Like__Food  
  #include<bits/stdc++.h>
  #include <ext/pb_ds/assoc_container.hpp> 
  #include <ext/pb_ds/tree_policy.hpp>
  #define rep(i,a,b) for(int i = a; i <=b; i++)
  #define rep2(i,a,b) for(int i = a; i>=b; i--)
  #pragma GCC optimize("O3")
  #pragma GCC optimize("Ofast") 
  #pragma GCC optimize("unroll-loops")
  using namespace std;
  using namespace __gnu_pbds;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define int long long
  #define all(v) v.begin(),v.end()
  #define PB push_back
  #define MP make_pair
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  const int mod = 1e9 + 7;
  const int N = 100005;
  const int INF = 1e16;
  const double PI = acos(-1);


int dp[10005][105][2];

int32_t main()
{
       

    IOS


    string s;
    cin >> s;

    int d;
    cin >> d;

    dp[0][0][0] = 1;

    

    for(int i = 0; i < s.length(); i++)
    {
      // i is terating over the string
      trace1(i);

      for(int j = 0; j < d; j++)
        {
          // j is iterating over the digit sum modulo d

          for(int k = 0; k < 2; k++)
          {
            /*
            if k is zero then we did'nt place a digit so far which 
            is less significant than the digit in the string so 
            */

            /*
            if k is one then we have placed placed a digit earlier 
            such that is less significant than the digit in the string 
            */
            for(int x = 0; x < 10; x++)
            {
              // x iterating over the digits we are placing at the ith position
              if(k == 0 and x > s[i]-'0')
              {
                continue;
                // if k is zero we can only place digits from 0 to the corresponding digit
                //in the string
              }
              int kk = k;
              if(x < s[i]-'0')
              {
                kk = 1;
                // if kk is one now we can only place digits from 0 to 9 due to the less significant digit placed before
              }
              dp[i+1][(j+x)%d][kk] += dp[i][j][k]%mod;
              dp[i+1][(j+x)%d][kk]%=mod;
            }
          }
        }
    }



    cout << (dp[s.length()][0][0]%mod + dp[s.length()][0][1]%mod - 1 + mod)%mod;
  return 0;
} 