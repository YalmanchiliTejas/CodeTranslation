#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<int> h(H,0);
  vector<int> w(W,0);
  vector<string> m(H);
  for (int i=0;i<H;i++){
    cin >> m[i];
  }
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      if (m[i][j]=='#'){
        h[i]=1;
        w[j]=1;
      }
    }
  }
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      if (h[i] & w[j])
        cout << m[i][j];
    }
    cout << endl;
  }
}
