#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int aux;
  int maior = 0;
  int cont = 0;

  while(n--) {
    cin >> aux;
    if(aux >= maior) cont++;
    maior = max(maior, aux);
  }

  cout << cont << endl;

  return 0;
}