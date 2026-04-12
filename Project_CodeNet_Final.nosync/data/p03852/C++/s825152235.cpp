#include <bits/stdc++.h>
#define ll long long
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

int main() {
  INIT;
  
  char c;
  cin >> c;
  if (c == 'a' ||c == 'i' ||c == 'u' ||c == 'e' ||c == 'o'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
  return 0;
}