#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

const int MOD = 1e9+7;

long long cnt[10001][2][100];

void addMod(long long* a, long long b){
  *a = (*a + b) % MOD;
}

int main(){

  string K;
  cin >> K;
  int D;
  cin >> D;

  memset(cnt, 0, sizeof(cnt));

  cnt[0][0][0] = 1;

  int sizeK = (int) K.size();
  for(int i = 1; i <= sizeK; i++){
    int digit = K[i - 1] - '0';
    
    for(int j = 0; j < D; j++){
      for(int k = 0; k < 10; k++){
	int nextState = (j + k) % D;
	if(k < digit){
	  addMod(&cnt[i][1][nextState], cnt[i - 1][0][j] + cnt[i - 1][1][j]);
	}
	else if(k == digit){
	  addMod(&cnt[i][0][nextState], cnt[i - 1][0][j]);
	  addMod(&cnt[i][1][nextState], cnt[i - 1][1][j]);
	}
	else{
	  addMod(&cnt[i][1][nextState], cnt[i - 1][1][j]);
	}
      }
    }
  }

  cout << (cnt[sizeK][0][0] + cnt[sizeK][1][0] + MOD - 1) % MOD << endl;
  
  return 0;
}
