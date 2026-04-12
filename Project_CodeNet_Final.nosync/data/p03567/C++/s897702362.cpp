#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define MP(x,y) make_pair(x,y)
#define X first
#define Y second
#define all(x) x.begin(), x.end()

using namespace std;
using ll= long long ;

int main(void){
  string s;
  cin >> s;
  bool flg = false;
  for(int i = 0; i < s.size()-1; ++i){
    if(s[i] == 'A' && s[i+1] =='C'){
      flg = true;
    }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;

}
