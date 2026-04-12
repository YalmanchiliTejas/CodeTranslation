#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  int maxh=-1,ans=0;
  rep(i,n){
    int h;
    cin>>h;
    if(maxh<=h){
      ans++;
      maxh=h;
    }
  }
  cout<<ans<<endl;
}
