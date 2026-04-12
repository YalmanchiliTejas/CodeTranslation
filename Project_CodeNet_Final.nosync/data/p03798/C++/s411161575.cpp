#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[] = {1, 1, 0, 0};
int dy[] = {1, 0, 1, 0};

int N;
vector<bool> a;
vector<bool> ans;


vector<bool> arr(bool fst, bool scd){
  vector<bool> tmp(N + 2, 0);
  tmp[N] = fst, tmp[0] = fst;
  tmp[1] = scd, tmp[N+1] = scd;
  
  for(int i = 2; i < N; i++){
    tmp[i] = (tmp[i-2] ^ tmp[i-1]) ^ a[i-1];
  }
  bool clr = 1;
  for(int i = N-1; i > 1; i--){
    bool prv = (tmp[i+2] ^ tmp[i+1]) ^ a[i+1];
    if(prv ^ tmp[i]) clr = 0;
  }
  
  if(!clr) tmp.clear();
  return tmp;
}

int main(){
  cin >> N;
  a.resize(N+2);
  ans.resize(N+1);
  for(int i = 1; i <= N; i++){
    char c; cin >> c;
    if(c == 'o') a[i] = 1;
    else a[i] = 0;
  }
  a[0] = a[N], a[N+1] = a[1];
  
  bool done = 0;
  for(int i = 0; i < 4; i++){
    ans = arr(dx[i], dy[i]);
    if(!ans.empty()){
      for(int i = 1; i <= N; i++){
        if(ans[i])  cout << 'S';
        else  cout << 'W';
      }
      done = 1;
      break;
    }
  }
  if(!done) cout << "-1" << endl;
}