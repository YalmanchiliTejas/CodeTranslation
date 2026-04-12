#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[33];
int main(void){
  string s;
  string al = "qwertasdfgzxcvb";
  for(int i = 0; i < (int)al.size(); i++){
    a[al[i]-'a'] = 1;
  }

  while(cin >> s && s != "#"){
    int h = a[s[0]-'a'];
    int res = 0;
    for(int i = 1; i < (int)s.size(); i++){
      if(h != a[s[i]-'a']){
	h = a[s[i]-'a'];
	res++;
      }
    }
    cout << res << endl;
  }
}