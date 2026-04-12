#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
#define traceV(v) for(auto x:v)cout<<x<<" ";cout<<endl
#define traceM(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl

bool judge(vector<int> v_now, vector<pair<int,int>> v_ref) {
  if(v_now[0]!=1)return false;

  rep(i, v_now.size()-1) {
    bool ok = false;
    int p1=v_now[i], p2=v_now[i+1];
    rep(j, v_ref.size()) {
      int a=v_ref[j].first, b=v_ref[j].second;
      if((p1==a&&p2==b)||(p1==b&&p2==a)) {ok = true; break;}
    }
    if(!ok)return false;
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M; cin>>N>>M;
  vector<pair<int,int>> v(M);
  rep(i,M) cin >> v[i].first >> v[i].second;

  vector<int> v_now(N); rep(i,N) v_now[i]=i+1;

  int res = 0;
  do {
    if(judge(v_now, v))++res;
  } while(next_permutation(ALL(v_now)));

  cout << res << endl;

  return 0;
}
