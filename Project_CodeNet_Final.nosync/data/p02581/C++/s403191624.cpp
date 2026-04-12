#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_range(i, s, e) for (int i = (s); i < (int)(e); i++)
#define rep_rev(i, s, e) for (int i = (s)-1; i >= (int)(e); i--)
#define sort_vec(v) sort((v).begin(),(v).end())
typedef int64_t lint;
// lint mod = 998244353;
// lint mod = 1000000007;
template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

int app() {
  int n;
  cin>>n;

  int n3=n*3;
  vector<int> a(n3);
  rep(i,n3){
    cin>>a[i];
    a[i]--;
  }

  vector<vector<int>> dp(n,vector<int>(n,-2e9));
  vector<int> maxi(n,-2e9),maxj(n,-2e9);
  int maxall=-2e9;

  vector<pair<pair<int,int>,int>> todo;
  auto set=[&](int i,int j,int v){ todo.emplace_back(make_pair(i,j),v); };
  auto get=[&](int i,int j)->int{ return (i<=j)?dp[i][j]:dp[j][i]; };
  auto upgrade=[&](){
    for(auto u:todo){
      int i=u.first.first;
      int j=u.first.second;
      int v=u.second;
      if(i<=j) chmax(dp[i][j],v);
      else chmax(dp[j][i],v);
      chmax(maxi[i],v);
      chmax(maxi[j],v);
      chmax(maxall,v);
    }
    todo.clear();
  };

  set(a[0],a[1],0);
  upgrade();

  int common=0;
  rep(t,n-1){
    int b=2+t*3;
    if(a[b]==a[b+1]&&a[b]==a[b+2]){
      common++;
      continue;
    }
    rep(s,3){
      int c=a[b+s];
      int o1=a[b+(s+1)%3];
      int o2=a[b+(s+2)%3];

      if(o1==o2){
        rep(j,n){
          set(c,j,get(o1,j)+1);
        }
      }
      rep(j,n){
        set(c,j,maxi[j]);
      }

      set(o1,o2,get(c,c)+1);
      set(o1,o2,maxall);
    }

    upgrade();
  }

  int ans=maxall;
  int c=a[n3-1];
  chmax(ans,dp[c][c]+1);

  return ans+common;
}

int main(){cout<<app()<<endl;return 0;}
