#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
const int inf= (int)(1e19+10LL);
void solve()
{
  int n;
  sl(n);
  Vl dp(n+1,0);
  Vl arr(n+1);
  for(int i=1;i<=n;i++)sl(arr[i]);
  Vl odd(n+1,0);
  odd[1]=arr[1];
  for(int i=3;i<=n;i+=2){
	  odd[i]=odd[i-2]+arr[i];
  }
  for(int i=2;i<=n;i++)
  {
	  if(i%2){
		  dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
	  }
	  else{
		  dp[i]=arr[i]+dp[i-2];
		  dp[i]=max(dp[i],odd[i-1]);
	  }
  }
  cout<<dp[n]<<endl;
		
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
