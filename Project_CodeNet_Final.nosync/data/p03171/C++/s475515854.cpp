#include<bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define pb   push_back
#define mk   make_pair
#define u_s  unordered_set
#define endl "\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define ll long long int
#define ipair pair<int,int>
#define all(x) (x).begin(), (x).end()

const int mod=pow(10,9)+7;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.first;
}
void open_file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void fast_io(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
      
}
/*
  ll C(ll n,ll k){
  
  if(k>n)return 0;
  
  ll ans=1;

  if(k>n-k)
    k=n-k;
  for(ll i=1;i<=k;i++)
    ans*=(n-i+1),ans/=i;

  return ans;
  }
  unsigned long long fact(long long a)
  {
  unsigned long long res=1;
  for(long long i=a;i>0;i--)
    res*=i;
  return res;
  }
  unsigned long long comb(long long a,long long b)
  {
  if((a-b)<b) b=a-b;
  if(a<=19) return fact(a)/(fact(a-b)*fact(b));
  if(a==b||b==0) return 1;
  if(b==1) return a;
  return comb(a-1,b-1)+comb(a-1,b);
  }
*/

ll dp[3005][3005];

ll game(vector<int>&A,int i,int j){

   if(i>j)return 0;

   if(dp[i][j]!=-1)return dp[i][j];

   ll way1=A[i]+min(game(A,i+2,j),game(A,i+1,j-1));
   ll way2=A[j]+min(game(A,i+1,j-1),game(A,i,j-2));
   return dp[i][j]=max(way1,way2);
}

void solve(){
   
   memset(dp,-1,sizeof dp);

   int n; cin>>n;
   ll sum=0;
   vector<int>A(n); for(int i=0;i<n;i++)cin>>A[i],sum+=A[i];

   ll X=game(A,0,n-1);
   ll Y=sum-X;

   cout<<X-Y;
}

int main(){

  //open_file();
  fast_io();
  
  solve();
  
  return 0;  
    
}
