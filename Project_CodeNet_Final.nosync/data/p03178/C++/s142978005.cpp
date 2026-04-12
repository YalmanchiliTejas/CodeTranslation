#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long
#define int long long
#define ld long double
#define endl '\n'
const int mod= 1e9+7;
#define F first
#define S second
//#define x first
//#define y second
#define pb push_back
#define mp make_pair
#define trace(x) cerr << #x << " is " << x << endl;
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n";
#define all(x) x.begin(),x.end()
#define reset(x,val) memset(x,val,sizeof(x))
#define flush fflush(stdout)
#define sz(a) a.size()
#define pii pair<int,int>
void fail(){std::cout<<"NO\n";exit(0);}
using namespace std;
string k;
const int N=1e5+5,D=105;
int cache[N][D][2],ip[N];
int n,d;
int dp(int idx,int rem,bool less)
{
 if(idx==n+1)return (rem==0);
 int &ans=cache[idx][rem][less];
 if(ans!=-1)return ans;
 ans=0;
 if(less)
 {
  for(int i=0;i<10;i++)
  {
   ans+=dp(idx+1,(rem+i)%d,less);
   ans%=mod;
  }
 }
 else
 {
  for(int i=0;i<=ip[idx];i++)
  {
   ans+=dp(idx+1,(rem+i)%d,less|(i<ip[idx]));
   ans%=mod;
  }
 }
 return (ans+mod)%mod;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    cin>>k>>d;
    n=k.size();
    reset(cache,-1);
    for(int i=0;i<n;i++)
    {
     ip[i+1]=k[i]-'0';
    }
    
    cout<<(dp(1,0,0)-1+mod)%mod<<endl;
    return 0; 
}