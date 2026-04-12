#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector <vector <char>> C(N, vector<char>(M));
  for (int i =0;i<N;i++){
    for (int j =0;j<M;j++){
      cin >>C.at(i).at(j);
    }
  }
  // (ここで空白のマスのみの行を削除)
  for (int k=0;k<N;k++){
  int sumM=0;
  for (int i=0;i<M;i++){
   if (C.at(k).at(i) == '.'){
     sumM ++;
   }
  }
   if (sumM == M){
   for (int j =0;j<M;j++){
     if (k<N-1){
       for (int i=k;i<N-1;i++){
       C.at(i).at(j) = C.at(i+1).at(j);
       }
       }
    }
     N--;
     k--;
   }
   } 
  // (ここで空白のマスのみの列を削除)
  for (int k=0;k<M;k++){
  int sumN=0;
  for (int i=0;i<N;i++){
   if (C.at(i).at(k) == '.'){
     sumN ++;
   }
  }
   if (sumN == N){
   for (int j =0;j<N;j++){
     if (k<M-1){
       for (int i=k;i<M-1;i++){
       C.at(j).at(i) = C.at(j).at(i+1);
       }
       }
    }
     M--;
     k--;
   }
   } 
  
  // (ここで2次元配列を出力)
  for (int i =0;i<N;i++){
   for (int j =0;j<M;j++){
    cout << C.at(i).at(j);
     if (j == M-1){
     cout << endl;      
     }
   }
  }
}