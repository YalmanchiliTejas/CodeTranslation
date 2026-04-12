#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;


ll rec(int N, ll X){
  if( N == 0){ return 1;} // ベース
  
  ll length = (1LL << ( N + 1 ) ) - 3;
  ll num = (1LL << ( N ) ) - 1;
  //レベルN - 1バーガーに帰着する
  
  if( X == 1){ return 0;}
  else if( X <= length + 1){ return rec( N - 1, X - 1);}
  else if( X == length + 2){ return num + 1;}
  else if( X <= 2 * length + 2){ return num + 1 + rec( N - 1, X - length - 2);}
  else if( X == 2*length + 3){ return 2* num + 1;}}


int main(){
  int N; ll X; cin >> N >> X;
  cout << rec(N,X) << endl; return 0;}
                              