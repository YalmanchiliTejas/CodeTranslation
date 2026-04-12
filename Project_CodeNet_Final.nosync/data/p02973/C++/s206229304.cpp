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

  multiset<int> ms;
  rep(i,N){
    auto it = ms.upper_bound(-v[i]);
    if(it == ms.end()){
      ms.insert(-v[i]);
    }else{
      ms.erase(it);
      ms.insert(-v[i]);
    }
  }
    
  cout << ms.size() << endl;
  
  return 0;
}
