#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll n,a[55],ans=0,s,k;
  cin>>n;
  fr(i,n) cin>>a[i];
  while(1){
    bool f=1;
    fr(i,n) f=f&&(a[i]<n);
    if(f) break;
    s=0;
    fr(i,n){
      if(a[i]<n) continue;
      k=a[i]/n;
      a[i]-=k*(n+1);
      ans+=k;
      s+=k;
    }
    fr(i,n) a[i]+=s;
  }
  cout<<ans<<endl;
}