#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;

  vector<int> v, w;
  rep(i,N){
    int a;
    cin >> a;
    if(i%2==0) v.push_back(a);
    else w.push_back(a);
  }

  vector<int> ret;
  if(N%2==0){
    reverse(ALLOF(w));
    rep(i,w.size()) ret.push_back(w[i]);
    rep(i,v.size()) ret.push_back(v[i]);
  }else{
    reverse(ALLOF(v));
    rep(i,v.size()) ret.push_back(v[i]);
    rep(i,w.size()) ret.push_back(w[i]);
  }

  rep(i,ret.size()){
    if(i>0) cout << " ";
    cout << ret[i];
  }
  cout << endl;
  
  return 0;
}
