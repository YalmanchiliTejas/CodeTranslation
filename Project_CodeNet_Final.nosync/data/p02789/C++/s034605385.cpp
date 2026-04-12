#define rep(i, n) for (int i=0; i < (int)(n); i++)
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int N;
int M;
int cnt;

void input(){
  cin >> N >> M;
}

void solve(){
  if(M == N){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

int main() {
  input();
  solve();
  return 0;    
}