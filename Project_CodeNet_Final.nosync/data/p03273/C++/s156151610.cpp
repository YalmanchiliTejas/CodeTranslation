#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<string> data(N);
  for (int i=0;i<N;i++){
    cin>>data[i];
  }
  vector<bool> row(N,false);
  vector<bool> col(M,false);
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      if(data.at(i).at(j)=='#'){
        row.at(i)=true;
        col.at(j)=true;
      }
    }
  }
  
  for (int i=0;i<N;i++){
    if(row.at(i)){
      for (int j=0;j<M;j++){
        if(col.at(j)){
          cout << data.at(i).at(j);
        }
      }
    cout<< endl;
    }
  }
}