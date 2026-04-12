#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main(){
  ll n;
  cin>>n;
  ll sum=0;
  ll ans=0;
  vector<ll> a(n);
  cin>>a[0];
  sum+=a[0];
  for(int i=1;i<n;i++){
    cin>>a[i];
    ans+=sum*a[i];
    ans=ans%(INF+7);
    sum+=a[i];
    sum=sum%(INF+7);
  }
  cout<<ans<<endl;
}
