#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int N;
vector<int> d;

bool able(){
  int MAX = d[0];
  rep(i,1,N - 1){
    if(i * 10 <= MAX){
      MAX = max(MAX,i * 10 + d[i]);
    }
    else{
      return false;
    }
  }
  return true;
}

int main(){
  cin >> N;
  d.resize(N);
  rep(i,0,N - 1){
    cin >> d[i];
  }
  bool a = able();
  reverse(all(d));
  bool b = able();
  if(a && b)
    cout << "yes" << endl;
  else 
    cout << "no" << endl;
}

