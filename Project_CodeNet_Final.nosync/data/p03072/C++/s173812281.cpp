#include<bits/stdc++.h>
using namespace std;

int main(){
  int num;
  int max = 0;
  int cnt = 0;
  
  cin >> num;
  
  vector<int> vec(num);
  for(int i = 0; i < num; i++) cin >> vec.at(i);
  
  for(int i = 0; i < num; i++){
    if(vec.at(i) >= max){
      max = vec.at(i);
      cnt++;
    }
  }
  
  cout << cnt;
}
