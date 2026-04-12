#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;

const int MOD=1000000007;
int INF=100100100100100;
int a[150];
signed main(){
  int n;cin>>n;
  rep(i,n)cin>>a[i];
  int ans=0;
  int ma=0;
  rep(i,n){
    if(ma<=a[i]){
      ans++;ma=max(ma,a[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
