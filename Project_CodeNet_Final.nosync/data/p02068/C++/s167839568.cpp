#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

bool a[MOD];
vector<int> sosu;
void mk(){
  for(int i=2;i<=1000000;i++){
    if(a[i]==0){
      sosu.push_back(i);
      for(int j=i;j<=1000000;j+=i){
	a[j]=1;
      }
    }
  }
}

signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  mk();
  int ans=0;
  int l[1000];
  int n;
  cin>>n;
  lp(i,n){
    cin>>l[i];
    if(l[i]!=1)sosu.push_back(l[i]);
    ans=max(ans,l[i]);
  }
  if(ans==1){
    cout<<0<<endl;
    return 0;
  }
  lp(i,sosu.size()){
    int now=sosu[i];
    int sum=0;
    lp(j,n){
      if(l[j]%sosu[i]==0){
	sum+=l[j];
      }
    }
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}

