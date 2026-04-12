#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;
 
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

vector<int>d;
int dp[105][105][2];

int solve(int pos,int c,int check,int mx)
{
  if(pos==d.size())
  {
    if(c<=mx)return 1;
    return 0;
  }
  if(dp[pos][c][check]!=-1)return dp[pos][c][check];

  int r;
  if(check)r=9;
  else r=d[pos];

  int res=0;
  for(int i=0;i<=r;i++)
  {
    int x=c;
    if(i!=0)
    x++;
    int y=check;
    if(i<r)
    y=1;
    res+=solve(pos+1,x,y,mx);


  }
  return dp[pos][c][check]=res;
}


int call(string s,int x)
{
  d.clear();

  while(s.size())
  {
    int k=s.back()-'0';
    d.push_back(k);
    s.pop_back();
  }

  reverse(d.begin(),d.end());
  memset(dp,-1,sizeof(dp));
  return solve(0,0,0,x);
}



int32_t  main()
{
 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 

  
  string s;
  cin>>s; int k;
  cin>>k;

  int x=call(s,k);
  int y=call(s,k-1);
  cout<<x-y<<"\n";









}