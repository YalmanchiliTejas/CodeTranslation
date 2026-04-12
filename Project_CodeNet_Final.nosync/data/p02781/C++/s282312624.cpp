#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 1e18;
const int nax = 105;
int num[nax];
int dp[nax][4][2];
string s;
int n,k;
int calc(int pos,int non_zero,bool smaller)
 {
	if(non_zero>k)
	  return 0;
	if(pos == n && non_zero == k)
	  return 1;
	else if(pos >= n)
	  return 0;
	if(dp[pos][non_zero][smaller] == -1)
	 {
	   int now = 0;
	   if(smaller)
	     now += calc(pos+1,non_zero,1) + 9*calc(pos+1,non_zero+1,1);
	   else
	      {
			if(num[pos] == 0)
			  now += calc(pos+1,non_zero,0);
			else
			  now += calc(pos+1,non_zero,1) + (num[pos] - 1)*calc(pos+1,non_zero+1,1) + calc(pos+1,non_zero+1,0);
		  }
	   dp[pos][non_zero][smaller] = now;
	 }
   return dp[pos][non_zero][smaller];
 }
void solve()
 {
  cin>>s>>k;
  n = s.size();
  memset(dp,-1,sizeof dp);
  loop(i,0,n)
   num[i] = s[i] -'0';
  int ans = calc(0,0,0);
  cout<<ans;  
 }  
signed main()
 {   
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  cout.tie(0); 
   /*int t;
   cin>>t;
   loop(i,1,t+1)*/
      solve();
      
  //cerr<<END<<1.0*clock();
  return 0;
} 
