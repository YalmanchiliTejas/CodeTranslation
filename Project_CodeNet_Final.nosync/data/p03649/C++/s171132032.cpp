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

int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  int f=1;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>=n)f=0;
  }
  if(f){
    cout<<0<<endl;
    return 0;
  }

  ll ans=0;
  
  ll A=0;
  for(int i=0;i<n;i++){
    ll t=a[i];
    ll ok=t,ng=-1,mid;
    while(ok-ng>1){
	 mid=(ok+ng)/2;
	 if(t-(mid*(n+1))<n)ok=mid;
	 else ng=mid;
    }
    a[i]-=ok*(n+1);
    A+=ok;
    ans+=ok;
  }

  if(A>n){
    ans+=(A-n)*n;
    A=n;
  }
  
  for(int i=0;i<n;i++)a[i]+=A;

  while(1){
    int f=1;
    ll ma=0;
    ll t;
    for(int i=0;i<n;i++){
	 if(a[i]>=n)f=0;
	 if(ma<a[i]){
	   t=i;
	   ma=a[i];
	 }
	 a[i]++;
    }
    if(f)break;
    ans++;
    a[t]-=n+1;
  }
  
  cout<<ans<<endl;
  return 0;
}
