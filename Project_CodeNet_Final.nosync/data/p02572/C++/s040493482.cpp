#include<bits/stdc++.h>
#define int long long int
#define rep(i,m,n) for(int i=m;i<n;i++)
#define repr(i,n,m) for(int i=n;i>=m ;i--)
#define mod 1000000007
#define float long double
#define pb push_back
#define mp make_pair
#define print(v1) rep(i,0,v1.size()){cout<<v1[i]<<" ";} cout<<"\n";
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int modulo(int n,int m=1000000007){
    if(n<0){
        return (m-abs(n)%m)%m;
    }
    else return n%m;
}
void solve()
{ 
   int n,total=0,final=0;
   cin>>n;
   vector<int>v1(n),v2(n+1);
   rep(i,0,n){
      cin>>v1[i];
      total+=(v1[i]);
    }
   v2[0]=0;
   int x=0;
   rep(i,1,n+1)
   {
    x+=v1[i-1];
   v2[i]=((total)-(x));    
   }
   // v2[i]=((total%mod)-(v1[i-1]%mod)-(v2[i-1]%mod))%mod;
   // print(v2);
   rep(i,0,n-1){
    final+=((v1[i])*(v2[i+1]%mod))%mod;
    final%=mod;
   }cout<<final%mod;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t=1;
   //cin>>t;
   while(t--)
   {
      solve();
      cout<<"\n";
   }
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
  return 0;
 }