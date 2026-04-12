#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct {
  ll B = 0;  //バン
  ll P = 1;  //パティ
  ll A = 1;  //全部
} bur;

int N;
ll X;
bur Bur[51];

void make_Bur(int n){
  for(int i = 1; i <= n; i++) { 
    Bur[i].B = 2 * Bur[i-1].B + 2; 
    Bur[i].P = 2 * Bur[i-1].P + 1;
    Bur[i].A = Bur[i].B + Bur[i].P;
  }
  return ;
}

ll dsf(ll X, int l){
  if(X == 0) return 0;
  if(l == 0) return 1;  //どうあがいてもパティ
  if(X == Bur[l].A) return Bur[l].P;
  if(X >= Bur[l].A/2+1) return Bur[l-1].P + 1 + dsf(X-Bur[l].A/2-1, l-1);
  if(X < Bur[l].A/2+1) return dsf(X-1, l-1);
  return -1;
}

int main(){
  cin >> N >> X;
  make_Bur(N);
  cout << dsf(X, N) << endl;
  //cout << Bur[N].A << " " << Bur[N].B << " " << Bur[N].P << endl;
  return 0;
}
