#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
/*
void chmin(ll a, ll b){if (a>b){a = b; return true;}return false;}
void chmax(ll a, ll b){if (a<b){a = b; return true;}return false;}
*/

const ll MOD = 1000000007;
const ll INF = 9999999999;

bool check(int N, string S, vector<int> &A){
  // Sは動物の回答結果、Aは各々が何の動物か。
  // A.at(0)とA.at(N-1)は予め決定されている。
  for (int i=0; i<N-2; i++){
    int pre = A.at((N+i-1)%N), next = -1;
    char c = S.at(i);
    if (A.at(i) == 1){
      if (c=='o') next = pre;
      else next = 1-pre;
    }else{
      if (c=='o') next = 1-pre;
      else next = pre;
    }
    A.at(i+1) = next;
  }
  // N-2まで全部埋まった。あとはN-2マンとN-1マンの回答の整合性を確認する
  for (int i=N-2; i<=N-1; i++){
    int pre = A.at(i-1), next = -1;
    char c = S.at(i);
    if (A.at(i) == 1){
      if (c=='o') next = pre;
      else next = 1-pre;
    }else{
      if (c=='o') next = 1-pre;
      else next = pre;
    }
    if (A.at((i+1)%N) != next) return false;
  }
  return true;
}

int main() {
  int N; cin >>N;
  string S; cin >>S;
  vector<int> A(N, -1); // i番目の動物の種類を格納。羊：1、狼：0、未決定：-1
  bool ok = false;
  for (int i=0; i<4; i++){
    A.at(0) = i/2, A.at(N-1) = i%2;
    // 00, 01, 10, 11の四通りある
    ok = check(N, S, A);
    if (ok) break;
    A.assign(N, -1);
  }
  if (ok){
    for (int i=0; i<N; i++){
      if (A.at(i) == 1) cout <<"S";
      else cout <<"W";
    }
    cout <<endl;
  }else{
    cout <<-1 <<endl;
  }
}