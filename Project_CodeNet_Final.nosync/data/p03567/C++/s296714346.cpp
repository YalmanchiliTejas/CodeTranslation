#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main(){

  string n;

  bool flag = false;
  cin >> n;

  int s = n.size();

  for(int i=0; i<s; i++){
    if(n[i]=='A' && n[i+1]=='C'){
      cout << "Yes" << endl;
      flag = true;
      break;
    }
  }

  if(!flag){
    cout << "No" << endl;
  }
  
  return 0;
}