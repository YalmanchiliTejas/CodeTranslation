#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1000000007;
int inf = INT_MAX;
int m_inf = INT_MIN;
int dp[100001][2];


int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	std::cout.unsetf ( std::ios::floatfield );
	std::cout.precision(6);
	string str;
  cin>>str;
  int a = 0,b = 0;
  for(int i = 0;i<str.size();i++)
  {
	if(str[i] == 'A')
      a++;
    else
      b++;
  }
  if(a && b)
    cout<<"Yes\n";
  else
    cout<<"No\n";
}