#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> data(n);
  for(int i = 0; i < n; i++){
    cin >> data.at(i);
  }
  int count = 0;
  int big_mount = data.at(0);
  for(int i = 0; i < n; i++){
    if(i == 0){
      count++;
    }
    else if(data.at(i) >= data.at(i - 1) && big_mount <= data.at(i)){
      count++;
      if(big_mount <= data.at(i)){
        big_mount = data.at(i);
      }
    }
  }
  cout << count << endl;
}