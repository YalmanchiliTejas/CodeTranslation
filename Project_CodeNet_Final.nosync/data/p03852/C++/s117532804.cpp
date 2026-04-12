#include<bits/stdc++.h>
#define rep(i, n) for(int (i)=0 ;i <(n); ++(i))
#define REP(i,m,n) for(int (i) = (m); (i) <= (n); ++(i))
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)? "YES":"NO")
typedef long long ll;
using namespace std;

int main() {
  char c;
  cin >> c;
  vector<char> vowel(5);
  vowel = {'a', 'i', 'u', 'e', 'o'};
  bool b = false;
  for(char p : vowel) {
    if(c == p) b = true;
  }
  b ? cout << "vowel" << endl : cout << "consonant" << endl;
  return 0;
}