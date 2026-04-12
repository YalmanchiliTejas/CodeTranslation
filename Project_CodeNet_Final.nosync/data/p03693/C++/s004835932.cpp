#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s = "";
  rep(i,3){
    string tmp; cin >> tmp;
    s+=tmp;
  }
  int a = stoi(s);
  if(a%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
