#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Na;
vector<ll> Np;
int N; ll X;

ll paty(ll layers, ll depth){
  ll eaten = layers;
  eaten += 1;
  if(eaten == X){  // eat bottom B
    return 0;
  }

  eaten += Na[depth-1];
  if(eaten > X){    // eat bottom BA[depth-1]
    return paty(eaten - Na[depth-1], depth - 1);
  }else if(eaten == X){
    return Np[depth-1];
  }

  eaten += 1;       // eat bottom BA[depth-1]P
  if(eaten == X){
    return Np[depth-1] + 1;
  }

  eaten += Na[depth-1];   // eat bottom BA[depth-1]PA[depth-1]
  if(eaten > X){
    return Np[depth-1] + 1 + paty(eaten - Na[depth-1], depth-1);
  }else if(eaten == X){
    return Np[depth-1] + 1 + Np[depth-1];
  }

  eaten += 1; // eat bottom BA[depth-1]PA[depth-1]B
  if(eaten == X){
    return Np[depth-1] + 1 + Np[depth-1];
  }
  assert(false);
}

int main(void){
  cin >> N >> X;

  Na = vector<ll>(51, 1);
  Np = vector<ll>(51, 1);
  for(int i = 1; i < 51; i++){
    Na[i] = 3 + 2 * Na[i-1];
    Np[i] = 1 + 2 * Np[i-1];
  }

  cout << paty(0, N) << endl;
}