#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
using namespace std;

int abs(int num){
   if (num > 0)
      return num;
   else
      return -num;
}

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  if((g*10+b)%4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}