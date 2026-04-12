#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
  int a[3] = {7,5,3};
  int b;
  cin >> b;
  for(int i = 0;i < 4;i++){
    if(i == 3){
      cout << "NO" << endl;
      break;
    }
    if(a[i] == b){
      cout << "YES" << endl;
      break;
    }
  }
}
