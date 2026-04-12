#include <bits/stdc++.h>
using namespace std;

int main(){
  int val,i,Mt,inn,Max;
  inn = 0;
  cin >> val;
  int hight[val];
  for(i=0;i<val;i++){
  	cin >> Mt;
    hight[i] = Mt;
  }
  Max = hight[0];
  for(i=0;i<val;i++){
    if(Max<=hight[i]) {
      inn++;
      Max = hight[i];
    }
  }
  cout << inn << endl;
}