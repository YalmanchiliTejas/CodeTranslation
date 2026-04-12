#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<string> s(n);
  rep(i,n) cin >> s.at(i);

  vector<int> alp(26,100);
  rep(k,26){
    if(alp.at(k)==0) continue;
    rep(i,n){
      int count=0;
      rep(j,s.at(i).size()){
        int now = (int)s.at(i).at(j) - 97;
        if(k==now) count++;
      }
      alp.at(k) = min(alp.at(k), count);
    }
  }

  rep(i,26){
    rep(j,alp.at(i)) cout << char(i+97);
  }
}