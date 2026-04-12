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
  int N;
  cin >> N;
  int wari = 0;
  wari = 200*(N/15);
  cout << 800*N - wari << endl;
}