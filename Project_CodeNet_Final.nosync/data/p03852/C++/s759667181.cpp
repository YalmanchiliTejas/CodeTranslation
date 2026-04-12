#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9




int main(){
  char c;
  cin >> c;
  if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u'){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }



  return 0;
}
