#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
  string a;
  cin >> a;
  int aa = 0;
  int bb = 0;
  for(int i = 0;i <= 2;i++){
    if(a[i] == 'A'){
      aa = 1;
    }
    else{
      bb = 1;
    }
  }
  if(aa == 1 && bb == 1){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}