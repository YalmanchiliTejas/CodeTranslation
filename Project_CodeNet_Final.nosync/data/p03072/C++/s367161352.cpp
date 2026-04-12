#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, high=0;
  cin >> n;
  vi h(n);
  rep(i, n)cin >> h[i];

  int ans=0;
  rep(i, n){
    int cnt=0;
    rep(j, i)if(h[i]>=h[j])cnt++;
    if(cnt==i)ans++;
  }

  cout << ans << endl;

  return 0;
}