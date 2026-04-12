#include <bits/stdc++.h>
#include <algorithm>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
using namespace std;

int main(){
  string s; //整数の数
  cin >> s;
  char *c = new char[3];
  for(int i=0; i<3; i++){
    c[i] = s.at(i);
  }
  
  if(c[0] == c[1] && c[1] == c[2]){
    cout << "No";
    return 0;
  }else{
    cout << "Yes";
    return 0;
  }
}