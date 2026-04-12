#include<bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vv = vector<vector<int>>;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  if( s.at(0) != s.at(1) || s.at(0) != s.at(2) || s.at(1) != s.at(2) ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;

  }
  return 0;
}
