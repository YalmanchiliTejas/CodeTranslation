#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for(ll i=0; i<N; ++i)

ll max(ll a, ll b) {return a < b ? b : a; }

char revc(char w) { 
  return w == 'W' ? 'S' : 'W';
}

int N; 
string s;

bool check(char c1, char c2) {
  string en;
  //狼，狼
  en.push_back(c1);
  en.push_back(c2);
  
  for(int i=1; i<N-1; ++i) {
    if(en.back() == 'W' && s.at(i) == 'o' ||
      en.back() == 'S' && s.at(i) == 'x') {
      en.push_back(revc(en[i-1]));
    } else {
      en.push_back(en[i-1]);
    }
  }
  
  char first =
    en.back() == 'W' && s.at(N-1) == 'o' ||
    en.back() == 'S' && s.at(N-1) == 'x' ?
    revc(en[N-1-1]) : en[N-1-1];
  
  char last = 
    en.front() == 'W' && s.front() == 'o' ||
    en.front() == 'S' && s.front() == 'x' ?
    revc(en[1]) : en[1];
    
  if(first == en[0] && last == en.back()) {
    cout << en << endl;
    return true;
  }
  return false;
}

int main() {
  cin >> N >> s;
  
  // bool found = false;
    //4パターンしか無い
    //狼=0, 羊=1 と置く
  if(check('W', 'W')) return 0;
  if(check('W', 'S')) return 0;
  if(check('S', 'W')) return 0;
  if(check('S', 'S')) return 0;
  
  cout << "-1" << endl;
  
  return 0;
}