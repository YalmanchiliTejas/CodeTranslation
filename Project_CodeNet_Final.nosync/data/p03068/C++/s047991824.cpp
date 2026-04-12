#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
  int N,K;
  string S;
  cin>>N>>S>>K;
  char k = S[K-1];
  for (int i(0);i<N;i++){
    if (S[i] == k) continue;
    S[i] = '*';
  }
  cout << S << endl;
  return 0;
}
