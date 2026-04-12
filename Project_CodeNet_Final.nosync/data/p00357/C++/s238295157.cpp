#include<iostream>
#include<cassert>
#include<algorithm>
#include<vector>
using namespace std;

bool solve(vector<int> v){
  int maxp = 0;
  for ( int i = 0; i < v.size(); i++ ){
    if ( i*10 <= maxp ){
      maxp = max(maxp, v[i] + i*10);
    }
  }
  return 10*(v.size()-1) <= maxp;
}

main(){
  int N; cin >> N;
  vector<int> v, u;
  for ( int i = 0; i < N; i++ ){
    int x; cin >> x; v.push_back(x);
  }
  u = v;
  reverse(u.begin(), u.end());

  cout << (solve(v)&&solve(u)?"yes":"no") << endl;

  return 0;
}


