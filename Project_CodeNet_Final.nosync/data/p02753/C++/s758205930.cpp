#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

set<char> s;

int main(){
  rep(i, 3){
    char tmp; cin >> tmp;
    s.insert(tmp);
  }
  if(s.size() == 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
