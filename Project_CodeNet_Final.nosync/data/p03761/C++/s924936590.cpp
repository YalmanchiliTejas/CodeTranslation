#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
using ll=long long;
#define MOD  1000000007


int flag[60][1000];

int main(int argc, char const *argv[]) {
  int n;
  int f=0;
  memset(flag,0,sizeof(flag));
  std::cin >> n;
  string s[50];
  for(int i=0; i<n; i++) std::cin >> s[i];

  for(int i=0; i<n; i++){
    for(int j=0; j<s[i].size(); j++){
      flag[i][s[i][j]]++;
    }
  }

for(int j='a'-0; j<='a'-0+25; j++){
  int mini=999;
  for(int i=0; i<n; i++){
    if(flag[i][j]<mini) mini=flag[i][j];
  }
  if(mini>0) f=1;
  for(int k=0; k<mini; k++) std::cout << (char)j;
}
if(f==1) std::cout  << '\n';

else if(f==0) std::cout << ' '<< '\n';
  return 0;
}
