#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(ll i=1;i<=n;i++){
    ans+=(n/i)*max((ll)0,i-k)+max((ll)0,n-(n/i)*i-k+1);
  }
  if(k==0)
    ans-=n;
  cout<<ans<<endl;
  return 0;
}
