#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 



int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S.at(i);
  
  vector<map<char, int>> memo(n);
  map<char, int> memo_all;
  rep(i, n){
    rep(j, S.at(i).size()){
      memo.at(i)[S.at(i).at(j)]++;
      memo_all[S.at(i).at(j)]++;
    }
  }
 
  map<char, int> res;
  
  for(const auto& x: memo.at(0)){
    int temp = memo.at(0)[x.first];
    rep(i, n){
      if(memo.at(i)[x.first] < temp) temp = memo.at(i)[x.first];
    }
    if(temp > 0) res[x.first] = temp;
  }
  
  for(auto&& it = res.begin(); it != res.end(); it++){
    rep(i, it->second) cout << it->first;
  }
  
  //for(auto&& it = memo.at(1).begin(); it != memo.at(1).end(); it++){
    //rep(i, it->second) cout << it->first;
  //}


 
}