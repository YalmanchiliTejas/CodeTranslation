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
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }

  multiset<int> s;
  for(int i=N-1; i>=0; i--){
    auto it = s.upper_bound(v[i]);
    if(it != s.end()){
      s.erase(it);
    }
    s.insert(v[i]);
  }

  cout << s.size() << endl;
  
  return 0;
}
