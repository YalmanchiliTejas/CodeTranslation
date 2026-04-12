#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define ll              long long
#define dd              double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vll             vector<long long>
#define vdd             vector<double>
#define vpii            vector<pair<int,int>>
#define vpll            vector<pair<long long,long long>>
#define vvi             vector<vector<int>>
#define vvl             vector<vector<long long>>
#define mii             map<int,int>
#define mll             map<long long,long long>
#define umii            unordered_map<int,int>
#define umll            unordered_map<long long,long long>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define rep(i,n)        for(int i=0;i<n;i++)
#define rep2(i,a,b)     for(int i=a;i<b;i++)
#define rev(i,n)        for(int i=n;i>=0;i--)
#define rev2(i,a,b)     for(int i=a;i>=b;i--)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             9e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fio             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            '\n'
#define all(x)          x.begin(),x.end()
#define d0(x)           cout <<x<<" "
#define d1(x)           cout <<x<<endl
#define d2(x,y)         cout <<x<<" "<<y<<endl
#define d3(x,y,z)       cout <<x<<" "<<y<<" "<<z<<endl
#define d4(x,y,z,w)     cout <<x<<" "<<y<<" "<<z<<" "<<w<<endl
#define read2(x,y)      cin>>x>>y
#define read3(x,y,z)    cin>>x>>y>>z
#define read4(x,y,z,w)  cin>>x>>y>>z>>w
#define read5(x,y,z,w,a)cin>>x>>y>>z>>w>>a
#define sz(a)           (int)a.size()
const ll mod=1e9+7;
const double PI = 3.14159265359;
const ll MOD=998244353;
void i_o()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}
string k;
ll d,n;
ll dp[10005][102][2];
ll mem(ll i,ll sum,int flag){
   if(i==n){
      if(sum==0) return 1;
      else return 0;
   }
   ll& res=dp[i][sum][flag];
   if(res!=-1) return res;
   res=0;
   ll lim;
   if(flag) lim=k[i]-'0';
   else lim=9;
   for(int j=0;j<=lim;j++){
      int flg;
      if(j==lim&&flag) flg=1;
      else flg=0;
      ll sum1=(sum+j)%d;
      res+=mem(i+1,sum1,flg);
   }
   res%=mod;
   return res;
}

int main() {
   fio
  // i_o();
   cin>>k;
   cin>>d;
   n=k.length();
   memset(dp,-1,sizeof(dp));
   ll ans=mem(0,0,1);
   ans--;
   ans+=mod;
   d1(ans%mod);
   return 0;
}

