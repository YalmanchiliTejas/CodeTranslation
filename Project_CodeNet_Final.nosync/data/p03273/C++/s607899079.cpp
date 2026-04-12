#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INFI = 1000000007;
const int mod = 1000000007;


int main(){
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0; i<H; i++){
    cin >> S[i];
  }
  vector<bool> h(H,false);
  vector<bool> w(W,false);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(S[i][j] == '#'){
        h[i] = true;
        w[j] = true;
      }
    }
  }
  for(int i=0; i<H; i++){
    if(!h[i]){
      continue;
    }
    for(int j=0; j<W; j++){
      if(w[j]){
        cout << S[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
