#include <bits/stdc++.h>

using namespace std;

int main()
{
  string left = "qwertasdfgzxcvb";
  string right = "yuiophjklnm";
  string s;
  while(cin >> s, s != "#"){
    int cnt = 0;
    for(int i = 0; i < s.size()-1; i++){
      if(left.find(s[i]) != string::npos && right.find(s[i+1]) != string::npos ||
	 left.find(s[i+1]) != string::npos && right.find(s[i]) != string::npos) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}