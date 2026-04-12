#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;cin>>N;vector<long long>V(N);
  long long U=0;long long O=1000000007;vector<long long>R(N);
  for(int X=0;X<N;X++){
    cin>>V[X];
  }
  int P=0;
  for(int X=N-1;X>=0;X--){
    R[X]=U;U+=V[X];U%=O;P++;
  }
  long long K=0;
  for(int X=0;X<N;X++){
    K+=V[X]*R[X]%O;
  }
  K%=O;
  cout<<K<<endl;
}