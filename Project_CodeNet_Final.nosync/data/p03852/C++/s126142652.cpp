#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <cstring>
#include <typeinfo>
#define REP(i,n) for(int i = 0;i < n ;i++)
#define FOR(i,m,n) for(int i= m ;i<n;i++)
using namespace std;

int main(void){
  string str;
  cin >> str;
  string a="aiueo";
  int i;
  for(i=0;i<5;i++){
  if(count(str.begin(),str.end(),a[i])>0){
    cout << "vowel" << endl;
    return 0;
  }
  //else b=false;
}
cout << "consonant" << endl;
  return 0;
}
