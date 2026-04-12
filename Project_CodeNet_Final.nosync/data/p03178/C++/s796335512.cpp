#include<bits/stdc++.h>

using namespace std;

#define sp << " " <<
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define int long long
#define double long double
#define INF 1e18
#define PI 3.14159265359

int power(int p,int y)
{
    int res=1;
    p=p%mod;
    while(y>0)
    {
        if(y&1)
            res=(res*p)%mod;
        y=y>>1;
        p=(p*p)%mod;
    }
    return res;
}

/*
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dice()
{
    uniform_int_distribution<int> uid(0,1);//specify l and r.
    return uid(rng) ;
}

int read()
{
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int dp = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          dp = dp * 10 + cc - '0';
          cc = getc(stdin);
       }
      return dp;
}

inline void print(int n)
{
  if (n == 0)
  {
    putchar('0');
    putchar('\n');
  }
  else if (n == -1)
  {
    putchar('-');
    putchar('1');
    putchar('\n');
  }
  else
  {
    char buf[20];
    buf[19] = '\n';
    int i = 18;
    while (n)
    {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n')
      putchar(buf[++i]);
  }
}

int n;

vector<vector<int>> mat_mul(vector<vector<int>> a,vector<vector<int>> b)
{
	vector<vector<int>> t(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				t[i][j]+=((a[i][k]*b[k][j])%mod);
				t[i][j]%=mod;
			}
		}
	}
	return t;
}

vector<vector<int>> pow_mat(vector<vector<int>> mat_a,int p)
{
	if(p==1)
        return mat_a;
	vector<vector<int>> temp=pow_mat(mat_a,p/2);
	vector<vector<int>> res=mat_mul(temp,temp);
	if(p&1)
        res=mat_mul(res,mat_a);
	return res;
}
*/

int dp[10013][100][2];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int d;
    cin >> s >> d;
    int n=s.length();
    for(int i=0;i<s[0]-'0';i++)
        dp[0][i%d][0]++;
    dp[0][(s[0]-'0')%d][1]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<d;k++)
            {
                int h=(j+k)%d;
                dp[i][h][0]=(dp[i][h][0]+dp[i-1][k][0])%mod;
                if(j<s[i]-'0')
                    dp[i][h][0]=(dp[i][h][0]+dp[i-1][k][1])%mod;
                else if(j==s[i]-'0')
                    dp[i][h][1]=dp[i-1][k][1];
            }
        }
    }
    cout << (dp[n-1][0][0]+dp[n-1][0][1]-1+mod)%mod;
    return 0;
}
