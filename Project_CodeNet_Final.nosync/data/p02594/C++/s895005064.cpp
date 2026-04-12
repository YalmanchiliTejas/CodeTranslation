#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair  
#define fi first
#define se second
#define pii pair<int,int> 
#define vi vector<int>
#define vpii vector<pii> 
#define vvpii vector<vetcor<pii>>
#define sz(V) ((int)V.size())
#define zeros(arr) memset(arr,0,sizeof(arr))
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define n1 "\n"
const int maxx  = 1e5+10 , limit = 1e17 , M=1e9+7 , max1 = 1e6;
#define PI 3.14159265
int pow(int x,int n){ if(n==0) return 1;  int res=pow(x,n/2); res=(res*res)%M;  if(n&1) res= (res*x)%M; return res;}
int calcInverse(int x,int n){ int res=1; while(n>0) { if(n&1)res=(res*x)%M;  x=(x*x)%M; n=n/2;} return res;}
#define test int t; cin>>t; while(t--)

int32_t main(){
    IOS       
    int x;cin>>x;
    if(x>=30)
      cout<<"Yes";
    else 
      cout<<"No";
    return 0;
}