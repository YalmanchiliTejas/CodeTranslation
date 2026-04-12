#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,0,n)cin>>s[i];
  string ans=s[0];
  
  rep(i,0,n){//s[i]
    map<char,int> cnt;
    rep(j,0,ans.size()){
      cnt[ans[j]]++; 
    }
    ans="";
    rep(j,0,s[i].size()){
      if(cnt[s[i][j]]){
        cnt[s[i][j]]--;
        ans+=s[i][j];
      }
    }
    
    
  }
  sort(all(ans));
  cout<<ans<<endl;
}