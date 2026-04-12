#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define int ll

using namespace std;

const int mod = 1e9+7;
const int N = 1e5+5;
string n;
int len;
int d;
vector<int> num;

int dp[N][2][105];

int digit(int idx,int tight,int sum){
  if(idx==-1){
    if(sum==0) return 1;
    else return 0;
  }
  if(dp[idx][tight][sum]!=-1)
    return dp[idx][tight][sum];
  int ans=0;
  int ch = n[idx]-'0';
  if(tight==1){
    for(int i=0;i<=ch;i++){
      if(i==ch){
        ans= (ans%mod + digit(idx-1,1,(sum+i)%d)%mod)%mod;
      }
      else{
        ans= (ans%mod + digit(idx-1,0,(sum+i)%d)%mod)%mod;
        //ans=ans%mod;
      }
    }
  }
  else{
    for(int i=0;i<=9;i++){
      ans= (ans%mod + digit(idx-1,0,(sum+i)%d)%mod)%mod;
    }
  }
  return dp[idx][tight][sum] = ans;
}


int32_t main()
{
   
    crap;
    cin>>n>>d;
    len = n.length();
    /*for(int i=0;i<len;i++){
      num.pb(n[i]-'0');
    }*/
    reverse(n.begin(),n.end());
    memset(dp,-1,sizeof(dp));
    int ans = digit(len-1,1,0);
    cout<<(ans-1+mod)%mod<<endl;
}