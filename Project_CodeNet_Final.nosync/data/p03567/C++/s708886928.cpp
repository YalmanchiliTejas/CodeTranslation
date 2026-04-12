#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int H,W,T;
string s[10];

int main(){
  string s;
  cin>>s;
  for(int i(0);i<int(s.size())-1;i++){
    if(s[i] == 'A' && s[i+1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
