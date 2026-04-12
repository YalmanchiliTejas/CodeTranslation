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
  int n;
  cin>>n;
  int ma=0,ans=0;
  for(int i=0;i<n;i++){
    int h;
    cin>>h;
    ma=max(ma,h);
    if(ma==h)ans++;
  }
  cout<<ans<<endl;
  return 0;
}
