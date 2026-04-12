# include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
int dp[10005][105][2];
int n;string str;int k;
//vector<int> v;
ll get(int pos,int sum,bool  f)
{ int & ans=dp[pos][sum][f];
  
  if(pos==n)
 { 
    if(sum%k==0) return (ans=1);
    else
      return (ans=0);
 }
 
 if(ans!=-1) return ans;
 ans=0;
  int lim=(f)? 9:(str[pos]-'0');
  for(int i=0;i<=lim;i++)
  { 
    ans=((ll)ans%mod+(get(pos+1,(sum+i)%k,f | (i<lim)))%mod)%mod;

  }
   return ans;
  
}

int main()
{  //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //string str;
 // cin.ignore();
  cin>>str;
  cin>>k;
  n=str.size();
 // cout<<str<<" ";
 //cout<<k<<" ";

   memset(dp, -1, sizeof (dp));
 cout<<(get(0,0,0)-1+mod)%mod;
  return 0;
  
}