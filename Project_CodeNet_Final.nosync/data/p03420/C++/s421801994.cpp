#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>

int n,k;
ll ans;

int main(){
  cin>>n>>k;

  for(int b=1;b<=n;b++){
    ans+= (n/b)*max(0,b-k);
    ans+= max(0,n%b-k+1);
  }
  if(k==0)
    ans-=n;

  cout<<ans<<endl;

  return 0;
}
