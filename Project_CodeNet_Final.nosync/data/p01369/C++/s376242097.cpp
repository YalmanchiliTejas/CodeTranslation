#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
  string s;
  string s1 = "qwertasdfgzxcvb";
  string s2 = "yuiophjklnm";
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  while(cin >> s, s != "#"){
    bool flag1, flag2;
    int cnt = 0;
    for(int i = 1 ; i < s.size() ; i++){
      if(binary_search(s1.begin(), s1.end(), s[i-1]) &&
	 binary_search(s1.begin(), s1.end(), s[i]) ||
	 binary_search(s2.begin(), s2.end(), s[i-1]) &&
	 binary_search(s2.begin(), s2.end(), s[i])) continue;
      else cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}