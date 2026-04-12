#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define int long long
# define mo 1000000000000007
#define gok ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[105][4][2],nn;
string s;
int k;
int help(int n,int k,int ch,int ex,int id)
{
    if(n<=0 || k<0)
    {
        if(n==0 && k==0)
            return 1;
        return 0;
    }
    if(dp[n][k][ch]!=-1)
        return dp[n][k][ch];
    int an=0;
  if(ch==1)
  {
      for(int i=0;i<=s[id]-'0';i++){
             if(i==s[id]-'0'){
                    if(s[id]!='0'){
                an += help(n-1,k-1,1,i,id+1);
                    }
             else{
                an += help(n-1,k,1,i,id+1);
             }
             }
                else if(i==0){
            an += help(n-1,k,0,i,id+1);
                }
            else{

                an+=help(n-1,k-1,0,i,id+1);
            }
      }
  }
  else
  {
      for(int i=0;i<=9;i++)
      {
          if(i==0){
            an+=help(n-1,k,0,i,id+1);
          }
            else{

                an += help(n-1,k-1,0,i,id+1);
            }
      }
  }
  dp[n][k][ch]=an;
  return an;
}
signed main(){
    gok
    cin>>s>>k;
    nn=s.size();
    memset(dp,-1,sizeof(dp));
    int an = help(nn,k,1,10,0);
    cout<<an;
     return 0;
}
