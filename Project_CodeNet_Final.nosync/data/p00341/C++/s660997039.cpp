#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

int main(){
  int e[12];
  for(int i=0;i<12;++i)
    cin >> e[i];
  sort(e,e+12);
  if(e[0]==e[3] && e[4]==e[7] && e[8]==e[11])
    cout << "yes" <<endl;
  else
    cout << "no" << endl;
  
}

