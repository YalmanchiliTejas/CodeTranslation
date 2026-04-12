 /******
Author:Ashraful Fuad Mehmet
University of Asia Pacific
date :07 Feb 2020
problem : https://codeforces.com/problemset/problem/639/B
*******/

#include<bits/stdc++.h>
#define input freopen("input.txt","r",stdin);
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;
int tc,cs=1,n,m,len;
void debug();
const int N=405;
template<class T> inline T sqr(const T &x)
{
  return x*x;
}/// end

ll dp[205][4][3];
 string s;
ll digitDP(int idx,int cnt,int flag)
{
 if(idx>=len)return cnt==n;

 if(cnt>n)return 0;

 ll ans=0;
  int p=s[idx]-'0';
  int l=p;
  if(flag){
    l=9;p=99;
  }

  ll &ret=dp[idx][cnt][flag];

  if(-1!=ret)
  {
   // cout<<"memo"<<endl;
    return ret;
  }

 
  for(int i=0;i<=l;++i)
  {
    int f=1;
    if(!flag&&i==l)f=0;
    if(i==0)
    {
      ans+=digitDP(idx+1,cnt,f);
    }
    else ans+=digitDP(idx+1,cnt+1,f);
  }

  return ret=ans;

}/// end func

void brain_fry()
{
 
 cin>>s;
 cin>>n;
 len=s.size();
  
  memset(dp,-1,sizeof dp);
 ll ans=digitDP(0,0,0);
 cout<<ans<<endl;
}// end func
int main()
{
  // input
  fastio
  brain_fry();
  // debug();
  return 0;
}
void debug()
{
  cout<<"Debug goes here"<<endl;
}