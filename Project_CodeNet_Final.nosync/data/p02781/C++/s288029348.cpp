#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  int K;
  cin >> N >> K;

  int Ndigits= N.size();
  vector<vector<int>> dp0(Ndigits+1, vector<int>(K+1)); // dp0.at(j).at(k)= #(上j桁がN未満である,0以外の数字がちょうどk個使われている整数)
  vector<vector<int>> dp1(Ndigits+1, vector<int>(K+1)); // dp1.at(j).at(k)= #(上j桁がNと一致する,0以外の数字がちょうどk個使われている整数)

  for(int i=1; i<Ndigits; i++){ dp0.at(i).at(0)= 1; }
  dp0.at(1).at(1)= N.at(0)- '1';
  dp1.at(1).at(1)= 1;
  for(int k=1; k<= K; k++){
    for(int i=2; i<= Ndigits; i++){
      if(N.at(i-1)=='0'){
        dp0.at(i).at(k)= 9* dp0.at(i-1).at(k-1)+ dp0.at(i-1).at(k);
        dp1.at(i).at(k)= dp1.at(i-1).at(k);
      }
      else{
        dp0.at(i).at(k)= 9* dp0.at(i-1).at(k-1)+ dp0.at(i-1).at(k)+ (N.at(i-1)-'1')* dp1.at(i-1).at(k-1)+ dp1.at(i-1).at(k);
        dp1.at(i).at(k)= dp1.at(i-1).at(k-1);
      }
    }
  }

  cout << dp0.at(Ndigits).at(K)+ dp1.at(Ndigits).at(K) << endl;
}