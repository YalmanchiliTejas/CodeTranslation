#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++) cin >> H[i];
  
  int cnt=0;
  for(int i=N; i>=0; i--){
    bool T=true;
    for(int j=i-1; j>=0; j--){
      if(!(H[i]>=H[j])) T=false;
    }
    if(T) cnt++;
  }

  cout << cnt << endl;
  return 0;
}