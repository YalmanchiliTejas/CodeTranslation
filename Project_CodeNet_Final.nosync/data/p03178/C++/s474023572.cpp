#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define srt(a) sort(a.begin(),a.end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define endl '\n'
#define mod 1000000007
#define INF64 1e18

const int maxn=10000,maxd=100;
int dp[maxn+5][2][maxd+5];
int n,d;
vi digit;
string s;

int solve(int pos,int flag,int remainder){
  if(pos==n)return remainder==0;
  if(dp[pos][flag][remainder]!=-1)return dp[pos][flag][remainder];

  int limit=flag?digit[pos]:9;
  int res=0;
  for(int i=0;i<=limit;i++){
    bool new_flag=flag&&(i==limit);
    res+=solve(pos+1,new_flag,(remainder+i)%d);
  }

  return dp[pos][flag][remainder]=res%mod;
}

int32_t main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  memset(dp,-1,sizeof(dp));
  cin>>s>>d;
  n=s.size();
  for(int i=0;i<n;i++)
    digit.pb(s[i]-'0');
  int ans=(mod+solve(0,1,0)-1)%mod;
  cout<<ans;
}