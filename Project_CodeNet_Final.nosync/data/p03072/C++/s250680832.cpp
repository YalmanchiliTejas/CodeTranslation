#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++) cin >> H[i];
  int ans=0;
  for(int i=0; i<N; i++){
      vector<int> W(i+1);
      for(int j=0; j<=i; j++){
          W[j]=H[j];
      }
      sort(W.begin(), W.end());
      if(W[i]==H[i]) ans++;
  }
  cout << ans << endl;
}