#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  int N,M;
  cin >> N >> M;
  set<pair<int,int>> a;
  rep(i,M){
    int x,y;
    cin >> x >> y;
    a.insert(make_pair(x,y));
    a.insert(make_pair(y,x));
  }
  int flag;
  vector<int> check(N-1);
  rep(i,N-1)
    check.at(i)=i;
  do{
    bool b=1;
    if(!a.count(make_pair(1,check.at(0)+2))){
      b=0;
    }
    rep(i,N-2){
      if(!a.count(make_pair(check.at(i)+2,check.at(i+1)+2))){
        b=0;
      }
    }
    if(b)
      flag ++;
  } while (next_permutation(check.begin(),check.end()));
  cout << flag << endl;
}
      
  