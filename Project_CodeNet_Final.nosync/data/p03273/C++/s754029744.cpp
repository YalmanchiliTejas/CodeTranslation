#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ll long long
 
int main(){
  int H, W;
  cin >> H >> W;
  string S[H];
  int SH[H];
  int SW[W];
  FOR(i, 0, H) cin >> S[i];
  int zero;
  int lSH = 0;
  int lSW = 0;
  int Hposi = 0;
  int Wposi = 0;
  
  FOR(i, 0, H){
    zero = 0;
    FOR(j, 0, W){
      if(S[i][j]=='#') zero++;
    }
    if(zero==0) SH[i] = 0;
    else SH[i] = 1;
  }
  
  FOR(j, 0, W){
    zero = 0;
    FOR(i, 0, H){
      if(S[i][j]=='#') zero++;
    }
    if(zero==0) SW[j] = 0;
    else SW[j] = 1;
  }
  
  FOR(i, 0, H){
    if(SH[i]==0){
      FOR(k, i, H-1) {
        FOR(l, 0, W) S[k-Hposi][l] = S[k+1-Hposi][l];
      }
      Hposi++;
    }
  }
  
  FOR(i, 0, W){
    if(SW[i]==0){
      FOR(k, i, W-1) {
        FOR(l, 0, H) S[l][k-Wposi] = S[l][k+1-Wposi];
      }
      Wposi++;
    }
  }    
      
    
  /*FOR(i, 0, H){
    zero = 0;
    FOR(j, 0, W){
      if(S[i][j]=='#') zero++;
    }
    if(zero==0){
      FOR(k, i, H-1) {
        FOR(l, 0, W) S[k][l] = S[k+1][l];
      }
    }
    //cout << S[i] << endl;
  }
  
  FOR(j, 0, W){
    zero = 0;
    FOR(i, 0, H){
      if(S[i][j]=='#') zero++;
    }
    if(zero==0){
      FOR(k, j, W-1) {
        FOR(l, 0, H) S[l][k] = S[l][k+1];
      }
    }
    //cout << S[i] << endl;
  }*/
  
  FOR(i, 0, H) lSH += SH[i];
  FOR(i, 0, W) lSW += SW[i];
 
  FOR(i, 0, lSH) {
    FOR(j, 0, lSW) cout << S[i][j];
    cout  << endl;
  }
  
  //cout << lSH << lSW << endl;
}

