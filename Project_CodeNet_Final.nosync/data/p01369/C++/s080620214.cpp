#include<bits/stdc++.h>
using namespace std;

string s = "yuiophjklnm";

int main(){
  string str;
  while(cin >>str){
    if(str=="#") break;
    int pf = -1;
    int ret = 0;
    for(int i=0;i<(int)str.size();i++){
      char c = str[i];
      int f=0;
      for(int j=0;j<(int)s.size();j++){
	if( s[j]==c ) f = 1;
      }
      if(pf == -1 ) {}
      else if( pf != f ) ret++;
      pf = f;
    }
    cout << ret << endl;
  }
}