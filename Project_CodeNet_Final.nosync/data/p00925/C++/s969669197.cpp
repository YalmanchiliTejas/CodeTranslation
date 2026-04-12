#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int) (n); i++)
#define ALL(v) (v).begin(), (v).end()
#define INF 1e9+7

using namespace std;

int main(){
  string str;
  cin >> str;
  int lres = str[0] - '0';
  for(int i=1; i<str.size(); i+=2){
    char ope = str[i];
    int tmp = str[i+1] - '0';
    if(ope == '+') lres += tmp;
    if(ope == '*') lres *= tmp;
  }
  vector<int> digits;
  int tmp = 1;
  for(int i=0; i<str.size()-1; i+=2){
    int digit = str[i] - '0';
    tmp *= digit;
    char ope = str[i+1];
    if(ope == '+') { digits.push_back(tmp); tmp = 1; }
  }
  digits.push_back(tmp * (str[str.size()-1] - '0'));
  int mres = 0;
  REP(i, digits.size()) mres += digits[i];
  int ans; cin >> ans;
  if(mres == ans and lres == ans) cout << "U" << endl;
  else if (mres == ans) cout << "M" << endl;
  else if (lres == ans) cout << "L" << endl;
  else cout << "I" << endl;
  return 0;
}