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
  char A;
  cin >> A;
  if(A == 'a' || A == 'i' || A == 'u' || A == 'e' || A == 'o'){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }
}