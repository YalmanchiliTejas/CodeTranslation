#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define INF 999999999
#define PRIME 1000000007
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int main(){
  int N,x;
  multiset<int> s;
  cin >> N;
  REP(i,N){
    cin >> x;
    if(s.empty()){
      s.insert(-x);
    }
    else{
      auto itr = s.upper_bound(-x);
      if(itr != s.end()) s.erase(itr);
      s.insert(-x);
    }
  }
  cout << (int)s.size() << endl;
  return 0;
}