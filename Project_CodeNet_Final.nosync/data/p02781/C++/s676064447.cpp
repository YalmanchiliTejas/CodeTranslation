#include<cstdio>
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

//Nは桁数が大きい場合があるので文字列として受け取る
string N;
vector<int> n;  //Nの各桁の数字を格納するベクター
long long dp[105][2][5];

int main(){
  cin>>N;
  int k; cin >> k;

  //ベクターnを構成
  for(auto a : N){
    n.push_back(a-'0');
  }
  int l = N.size();  //nの長さ

  dp[0][0][0] = 1;
  for(int i = 0; i < l; i++){
    for(int smaller = 0; smaller < 2; smaller++){
      for(int j = 0; j < 4; j++){
        for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
          dp[i + 1][smaller || x < n[i]][j + (x!=0)] += dp[i][smaller][j];
        }
      }
    }
  }

  cout << dp[l][0][k] + dp[l][1][k] << endl;

  return 0;
}