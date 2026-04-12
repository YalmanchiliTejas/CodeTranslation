#include <bits/stdc++.h>
#define double long double
#define int long long
#define mii map<int,int>
#define pii pair<int,int>
#define low lower_bound
#define upp upper_bound
#define mod 1000000007 //10^9+7
#define inf (int)50000000000000000 //5･10^16
#define rep(i,n) for(int i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define vsort(vec) sort(all(vec))
#define vrever(vec) reverse(all(vec));
#define vunsort(vec) vsort(vec); vrever(vec);
#define bisea binary_search
#define cend cout<<endl;
#define F first
#define S second
using namespace std;
int n,m;
int g[10][10];
signed main() {
  cin>>n>>m;
  rep(i,m) {
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    g[a][b]=1;
    g[b][a]=1;
  }
  vector<int>vec;
  rep(i,n-1) {
    vec.push_back(i+1);
  }
  int cnt=0;
  bool can=true;
  can=true;
  if(g[0][vec[0]]==0) can=false;
  rep(i,n-2) {
    if(g[vec[i]][vec[i+1]]==0) {
      can=false;
    }
  }
  if(can) cnt++;
  while(next_permutation(all(vec))) {
    can=true;
    if(g[0][vec[0]]==0) can=false;
    rep(i,n-2) {
      if(g[vec[i]][vec[i+1]]==0) {
        can=false;
      }
    }
    if(can) cnt++;
  }
  cout<<cnt<<endl;
}