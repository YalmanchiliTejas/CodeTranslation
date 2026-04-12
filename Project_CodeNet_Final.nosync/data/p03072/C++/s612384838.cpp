#include<bits/stdc++.h>
using namespace std;


int main(){       
  int N;  cin >> N;
  int num = 0;

  int max = 0;
  for(int i = 0; i < N; i++){
    int val;  cin >> val;
    if(max <= val){                   //見える...
      max = val;                          //後ろのホテルはmax(val)以上求
      num++;                               //条件に該当するホテル
    }
  }
  
  cout << num << endl;
  return 0;
  
}
  