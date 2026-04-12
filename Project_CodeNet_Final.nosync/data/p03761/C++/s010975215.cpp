#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,len,kaisuu = 0;
  string mojiretu;
  char moji;
  vector<int> min_cnt(30,10000);
  cin >> n;
  vector<int> moji_cnt(30);
  
  for(int i = 0; i < n ; i++){
    cin >> mojiretu;
    len = mojiretu.size();
    for(int j = 0; j < len; j++){
      moji = mojiretu.at(j);
      moji_cnt.at(moji - 'a')++;
    }
    
    for(int k = 0; k < 26; k++){
      if(min_cnt.at(k) > moji_cnt.at(k))
         min_cnt.at(k) = moji_cnt.at(k);
      moji_cnt.at(k) = 0;
    }
    
  }
  
  for(int k = 0; k < 26; k++){
    while(kaisuu < min_cnt.at(k)){
      cout << char('a' + k);
      kaisuu++;
    }
    kaisuu = 0;
  }
    
}