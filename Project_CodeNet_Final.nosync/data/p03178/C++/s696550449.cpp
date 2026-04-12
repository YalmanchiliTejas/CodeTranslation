// g++ -std=c++14

//Difficulty according to solve count during contest:
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;


string k;
int d;
int n;
vector<vector<vector<int> > > dp;

int func(int pos, int rem, int check){
  if(pos == n and rem == 0)
    return 1;
  else if(pos == n)
    return 0;
  if(dp[pos][rem][check] != -1)
    return dp[pos][rem][check];
  dp[pos][rem][check] = 0;
  int maxDigit = 0;
  if(check == 0)
    maxDigit = k[pos] - '0';
  else
    maxDigit = 9;
  for(int i = 0; i <= maxDigit; i++){
    int newCheck = check;
    if(check == 0 and i < maxDigit)
      newCheck = 1;
    dp[pos][rem][check] += func(pos + 1, (rem + i) % d, newCheck);
    dp[pos][rem][check] %= mod;
  }
  return dp[pos][rem][check];
}


int32_t main(){
  cin >> k;
  cin >> d;
  n = (int)k.size();
  dp.resize(n, vector<vector<int> > (d, vector<int>(2, -1)));
  int ans = func(0, 0, 0);
  cout << (ans - 1 + mod) % mod << endl;
}
