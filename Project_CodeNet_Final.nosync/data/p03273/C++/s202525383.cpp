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
// #include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> S(H,vector<char> (W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> S[i][j];
    }
  }
  vector<int> h(105,0);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(S[i][j] == '#'){
        h[i]++;
        break;
      }
    }
  }
  vector<int> w(105,0);
  for(int i=0; i<W; i++){
    for(int j=0; j<H; j++){
      if(S[j][i] == '#'){
        w[i]++;
        break;
      }
    }
  }
  for(int i=0; i<H; i++){
    if(h[i] == 0){
      continue;
    }
    for(int j=0; j<W; j++){
      if(w[j] == 0){
        continue;
      }
      cout << S[i][j];
    }
    cout << endl;
  }
  return 0;
}
