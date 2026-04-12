#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void){
  int a,b;
  char n[10] = "";
  cin >> a >> n >> b;

  char pt = n[b-1];
  for(int i = 0;i < a;++i){
    if(n[i] != pt){
      n[i] = '*';
    }
  }

  cout << n << endl;
}
