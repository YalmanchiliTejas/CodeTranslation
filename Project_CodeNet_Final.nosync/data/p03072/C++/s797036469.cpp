#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
const ll INF=100000000000000001;
const double PI=3.141592653589;


int main(){
  int n; cin>>n;
  vector<int> h(n);
  rep(i,n) cin>>h[i];

  int ans=0;
  int mh=-1;
  for(int i=0;i<n;i++){
    if(mh<=h[i])
    ans++;
    mh=max(mh,h[i]);
  }
  cout<<ans<<endl;
  return 0;
}
