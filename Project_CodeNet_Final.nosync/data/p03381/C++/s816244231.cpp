#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
ll inf=1e10;

int main(){
  int N,X[200000],Y[200000];
  cin>>N;
  for (int i(0);i<N;i++) cin>>X[i];
  for (int i(0);i<N;i++) Y[i]=X[i];
  sort(X,X+N);
  int kouho1 = X[N/2],kouho2 = X[N/2-1];
  for (int i(0);i<N;i++){
    if (Y[i] >= kouho1) cout << kouho2 << endl;
    else if (Y[i] <= kouho2) cout << kouho1 << endl;
  }
  return 0;
}
