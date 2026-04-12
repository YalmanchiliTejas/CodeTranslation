#include <bits/stdc++.h>

using namespace std;

int main(){
  int e[12];
  for(int i=0;i<12;++i) cin >> e[i];
  sort(e,e+12);
  bool flag=true;
  for(int i=0;i<3;++i) {
    if(!(e[4*i]==e[4*i+1]&&e[4*i+1]==e[4*i+2]&&
	 e[4*i+2]==e[4*i+3]&&e[4*i+3]==e[4*i])) flag=false;
  }
  cout << (flag?"yes":"no") << endl;
  
  return 0;
}

