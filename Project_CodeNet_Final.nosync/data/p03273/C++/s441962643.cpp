#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

 vector<vector<char>> chart(N,vector<char>(M));
 vector<vector<char>> answer(N,vector<char>(M));
 vector<bool> row(N,false);
 vector<bool> col(M,false);
 for (int i = 0; i < N; i++) {
   for (int j = 0; j < M; j++){
    cin >> chart.at(i).at(j);
   }
 }
 for (int i = 0; i < N; i++) {
   for (int j = 0; j < M; j++){
    if ((chart.at(i).at(j) == '#')){
      row.at(i) = true;
      col.at(j) = true;
    }
   }
 }
 for (int i = 0; i < N; i++) {
  if(row.at(i)) {
   for (int j = 0; j < M; j++){
    if (col.at(j))  cout << chart.at(i).at(j);
   }
   cout << endl; 
  }
 } 
}