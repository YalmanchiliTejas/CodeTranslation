#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*バーガーの構造*/
typedef struct {
  ll B = 0;  //バン
  ll P = 1;  //パティ
  ll A = 1;  //全部
} bur;

int N;
ll X;
bur Bur[51];  //バーガーレシピ

/*各レベルのバーガーレシピの作成*/
void make_Bur(int n){
  for(int i = 1; i <= n; i++) { 
    Bur[i].B = 2 * Bur[i-1].B + 2; 
    Bur[i].P = 2 * Bur[i-1].P + 1;
    Bur[i].A = Bur[i].B + Bur[i].P;
  }
  return ;
}

/*食った層の内訳(パティ)を返す*/
ll dsf(ll X, int l){
  if(X == 0) return 0;  //必要量食ったわ
  if(l == 0) return 1;  //食うとしても...どうあがいてもパティ
  if(X >= Bur[l].A/2+1) return Bur[l-1].P + 1 + dsf(X-Bur[l].A/2-1, l-1);  //半分以上食える
  if(X < Bur[l].A/2+1) return dsf(X-1, l-1);  //今のバーガーを半分も食えない
  return -1;
}

int main(){
  cin >> N >> X;
  make_Bur(N);
  cout << dsf(X, N) << endl;
  return 0;
}
