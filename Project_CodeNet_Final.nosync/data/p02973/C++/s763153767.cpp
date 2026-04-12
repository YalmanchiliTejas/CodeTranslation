#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI=3.14159265358979323846;
const int waru = 1000000007;
const int INF=2000000000;
#define vec2(a,y,x) vector<vector<int>> a(y,vector<int>(x,INF))
#define vec1(a,n) vector<int> a(n);rep(i,n)cin>>a[i]

int main(){
int n;cin>>n;
  vec1(a,n);
  reverse(all(a));
  vector<int> dp(n,INF);//dp[i]:=i+1文字の部分列の最後の文字の最小値
  rep(i,n) *upper_bound(all(dp),a[i])=a[i];
  cout<<lower_bound(all(dp),INF)-dp.begin()<<endl;
}