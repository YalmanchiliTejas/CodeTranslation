#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()

int main(){
  int n;
  cin >> n;
  vector<int> a;
  REP(i, n){
    int d;
    cin >> d;
    auto it = upper_bound(ALL(a), -d);
    if(it == a.end()){
      a.push_back(-d);
    }else{
      *it = -d;
    }
  }
  cout << a.size() << endl;
  return 0;
}