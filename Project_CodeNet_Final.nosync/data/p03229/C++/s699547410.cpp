#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
int main(){
  int n;
  cin>>n;
  vector<int> a(n+1,0);
  vector<int> ans(n+1,0);
  rep1(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  ll sum=0;
  if(n%2==0){
    int k=n/2;
    rep(i,k){
      sum+=a[n-i]*2;
      sum-=a[i+1]*2;
    }
    sum-=a[k+1];
    sum+=a[k];
  }
  else{
    int k=n/2;
    ll buf1=0;
    ll buf2=0;
    rep(i,k){
      buf1+=a[n-i]*2;
      buf1-=a[i+1]*2;
      buf2+=a[n-i]*2;
      buf2-=a[i+1]*2;
    }
    buf1+=a[n-k];
    buf1-=a[n-k+1];
    buf2-=a[n-k];
    buf2+=a[n-k-1];
    sum=buf1;
    if(buf1<buf2)sum=buf2;
  }
  cout<<sum<<endl;
  return 0;
}
