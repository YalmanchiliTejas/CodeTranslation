#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int n, m;
  cin >> n >> m;
  vector<string> dataset; 
  dataset.resize(n, "");
  
  for(int i = 0; i < n; i++){
    cin >> dataset[i];
  }
  for(int i = 0; i < n; i++){
    int count = 0;
    for(int j = 0; j < m ; j++){
      if(dataset[i][j] == '.'){
        count++;
      }
    }
    if(count==m){
      for(int j = 0; j < m ; j++){
        dataset[i][j] = 'x';
      }
    }
  }
  for(int i = 0; i < m; i++){
    int count = 0;
    for(int j = 0; j < n ; j++){
      if(dataset[j][i] == '.' || dataset[j][i] == 'x'){
        count++;
      }
    }
    if(count==n){
      for(int j = 0; j < n ; j++){
        dataset[j][i] = 'x';
      }
    }
  }
  
  for(int i = 0; i < n; i++){
    int flag = 0;
    for(int j = 0; j < m ; j++){
      if(dataset[i][j] != 'x'){
        cout << dataset[i][j];
        flag = 1;
      }
    }
    if(flag == 1){
      cout << endl;
    }
  }
}