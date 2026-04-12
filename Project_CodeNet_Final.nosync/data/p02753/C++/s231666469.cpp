#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n,m,a[10];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  char s[3];
  cin >> s;
  int ok = 0;
  for(int i = 0; i < 2; i++){
    if(s[i] != s[i + 1]){
      ok = 1;
      break;
    }
  }
  if(ok){
    cout << "Yes";
  }else{
    cout << "No";
  }


}
