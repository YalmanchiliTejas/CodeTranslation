#include <bits/stdc++.h>
using namespace std;

string k;

int d;

#define MOD 1000000007

long long memo[10010][100][2];

long long dp(int i, int num, int giri){
  if(i == k.size()){
    if(num == 0){
      return 1;
    }else{
      return 0;
    }
  }

  if(memo[i][num][giri] != -1) return memo[i][num][giri];

  int fin = '9';
  if(giri == 1){
    fin = k[i];
  }

  long long ans = 0;
  for(int j = '0';j <= fin;j++){
    int tmp = 0;
    if(giri == 1 && j == fin){
      tmp = 1;
    }
    ans += dp(i+1, (num+(j-'0'))%d, tmp);

    ans %= MOD;
  }

  return memo[i][num][giri] = ans;
}

int main(){
  cin >> k >> d;

  memset(memo, -1, sizeof(memo));

  cout << (MOD + dp(0, 0, 1) - 1) % MOD << endl;

  return 0;
}