#include <bits/stdc++.h>
using namespace std;
int N, M;
int ans = 0;


void solver(int from, int to, vector<bool> S, vector<bool> T, vector< vector<bool> > gr);

int main(){
  cin >> N >> M;
  int a,b;
  vector< vector<bool> > gr(9, vector<bool>(9, false));
  for(int i = 0; i< M; i++){
    cin >> a >>  b;
    gr.at(a).at(b) = true;
    gr.at(b).at(a) = true;
  }
  vector<bool> S(9, false);
  vector<bool> T(9, true);
  solver(0, 1, S, T, gr);

  cout << ans << endl;
  return 0;
}

void solver(int from, int to, vector<bool> S, vector<bool> T, vector< vector<bool> > gr){
  // printf("%d %d\n", from, to);

  S.at(to) = true;
  T.at(to) = false;

  gr.at(from).at(to) = false;
  gr.at(to).at(from) = false;
  for(int i=1;i<N+1; i++){
    if(T.at(i) == true){
      break;
    }else{
      if(i == N){
        ans++;
      }
    }
  }
  for(int i = 1; i< N+1; i++){
    if(gr.at(to).at(i)){
      if(S.at(i) == false){
        solver(to, i, S, T, gr);
      }
      //もし通れるなら行ってみる
    }
  }
}
