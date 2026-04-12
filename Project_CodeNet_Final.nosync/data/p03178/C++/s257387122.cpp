#include<bits/stdc++.h>
using namespace std;
#define int long long
#define tc int t; cin>>t; while(t--)
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define pb push_back
#define vi vector<int>
#define vc vector<char>
#define eb emplace_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fo(i,x,n) for(int i=x;i<n;i++)
#define csb(x) __builtin_popcount(x)
#define tz(x) __builtin_ctz(x)
#define lsbp(x) __builtin_ffs(x)
#define msbp(x) __lg(x)
#define btoi(str,i) stoi(str,0,i)
#define ff first
#define ss second
const int inf=0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
string s;
int dp[10001][101][2];
int f(int pos,int ss,int d,int tight){
   int ub=tight?s[pos]-'0':9;
   if(dp[pos][ss][tight]!=-1)return dp[pos][ss][tight];
   int x=s.size();
   if(pos==x-1){
      int cnt=0;
      for(int i=0;i<=ub;i++){
         //s[pos]+i-'0';
         if((i)%d==ss)cnt+=1;
      }
      return cnt;
   }
   int cnt=0;
   for(int i=0;i<=ub;i++){
      cnt=(cnt+f(pos+1,(d+ss-i%d)%d,d,tight&(i==ub)))%mod;
   }
   return dp[pos][ss][tight]=cnt;
}
int32_t main(){
cin>>s;
int d;cin>>d;
memset(dp,-1,sizeof(dp));
int ans=f(0,0,d,1);
ans-=1;
cout<<(ans+mod)%mod<<endl;
}