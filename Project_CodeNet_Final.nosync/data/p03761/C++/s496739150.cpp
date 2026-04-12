#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <typeinfo>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  for(int i=0;i<n;i++)  cin >> S.at(i);

  vector<char> abc(26);
  for(int i=0;i<26;i++){
    int count=50;
    for(int j=0;j<n;j++){
      int x=0;
      for(int k=0;k<S.at(j).size();k++){
        if(S.at(j).at(k)-'a'==i)  x++;
      }
      count=min(count,x);
    }
    abc.at(i)=count;
  }

  for(int i=0;i<26;i++){
    for(int j=0;j<abc.at(i);j++){
      printf("%c",i+'a');
    }
  }
  cout << endl;

  return 0;
}
