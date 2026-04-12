#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i,num,max;
  cin >> n;
  vector<int> vec(n);
  for (i = 0;i < n;i++){
    cin >> vec[i];
  }
  max = vec[0];
  num = 1;
  for (i = 1;i < n;i++){
    if (vec[i] >= max){
      num++;
      max = vec[i];
    }
  }
  cout << num << endl;
}