#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
string s;
ll d,p=1e9+7,dp[10010][2][110];

ll dfs(int si=0,int mx=1,int re=0){
  // cout<<si<<" "<<mx<<" "<<re<<endl;
  if(dp[si][mx][re]!=-1)return dp[si][mx][re];
  ll sum=0;
  if(si==(int)s.size())return re==0;
  if(mx==1){
    int r=s[si]-'0';
    sum+=dfs(si+1,1,(re+r)%d);
    sum%=p;
    for(int i=0;i<r;i++){
	 sum+=dfs(si+1,0,(re+i)%d);
	 sum%=p;
    }
    return dp[si][mx][re]=sum;
  }
  
  for(int i=0;i<10;i++){
    sum+=dfs(si+1,0,(re+i)%d);
    sum%=p;
  }
  return dp[si][mx][re]=sum;  
}

int main(){
  cin>>s>>d;
  fill_n(**dp,10010*2*110,-1);
  cout<<(p+dfs()-1)%p<<endl;
  return 0;
}
