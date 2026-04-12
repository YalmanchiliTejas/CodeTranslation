#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W; cin >> H >> W;
  int k=H+W-1;
  int s=H*W;
  char v;
  int count=0;
  for(int i=1;i<=s;i++){
    cin >> v;
    if(v=='#'){
      count++;
    }
  }
  if(count==k){
    cout << "Possible" << endl;
  }
  else cout << "Impossible" << endl;
}
    