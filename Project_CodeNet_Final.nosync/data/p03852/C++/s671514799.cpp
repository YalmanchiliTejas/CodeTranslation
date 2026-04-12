#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;

int main(){
  string str = "aeiou";
  char c;
  cin >> c;
  if((int)str.find(c) >= 0){
    puts("vowel");
  } else{
    puts("consonant");
  }
  return 0;
}