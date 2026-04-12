#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++) cin >> H.at(i);
  int ans=1;
  for(int i=1; i<N; i++){
    int cnt=0;
    for(int j=0; j<i; j++){
      if(H.at(j)<=H.at(i)) cnt++;
    }
    if(cnt==i) ans++;
  }
  cout << ans << endl;
}