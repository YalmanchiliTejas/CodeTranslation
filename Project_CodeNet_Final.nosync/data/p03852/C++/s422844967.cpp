#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  char c;
  cin>>c;
  char ans[5]={'a','i','u', 'e','o'};
  string an="consonant";
  for(auto x:ans){
    if(x==c){
      an="vowel";
    }
  }
  cout<<an<<endl;
}