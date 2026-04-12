#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ull unsigned long long
#define mp make_pair
#define F first
#define S second
#define mod 1000000007

ll dp[10005][105][2];

int main()
{
    string s;
    cin >> s;
    int d;
    cin >> d;

    dp[0][0][true] = 0;
    dp[0][0][false] = 1;

    for(int i=1; i<=s.size();i++)
    {
        int cur = s[i-1]-'0';
        for(int remainder=0; remainder<d; remainder++)
        {
            bool ar[2];
            ar[0] = true;
            ar[1] = false;
            for(bool small:ar) 
                for(int j=0;j<10;j++)
                {
                    if(j > cur && !small)
                    {
                        break;
                    }
                    dp[i][(remainder+j)%d][small ||  j<cur] = (dp[i][(remainder+j)%d][small || j<cur ]
                                            + dp[i-1][remainder][small])%mod ;
                }
        }
    }
	
  int ans = (dp[s.size()][0][true] + dp[s.size()][0][false])%mod;
  ans--;
  if(ans<0)
  	ans+=mod;
   cout << ans << endl;

}
