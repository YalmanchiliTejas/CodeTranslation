#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int n;
  cin >> n;

  map<char, int> m1;
  string s;
  cin >> s;
  REP(j,s.size())m1[s[j]]++;

  REP(i,n-1){
    cin >> s;

    map<char, int> m2;
    REP(j,s.size()){
      m2[s[j]]++;
    }
    for(auto iter = m1.begin(); iter != m1.end(); iter++){
      iter->second = min(iter->second, m2[iter->first]);
    }

  }
  for(auto iter = m1.begin(); iter != m1.end(); iter++){
    REP(i,iter->second)cout << iter->first;
  }
  cout << endl;
}

