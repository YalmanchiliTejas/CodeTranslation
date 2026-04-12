#include <bits/stdc++.h>

using namespace std;
int N;
string s[4] = {"SS","SW","WW","WS"};
string tmp;

int main() {
  cin >> N >> tmp;

  for(int i = 0; i < 4; i++) {
    string ans = s[i];
    for(int j = 1; j <= N;j++) {
      if(tmp[j%N] == 'o') {
	if(ans[j] == 'S') {
	  if(ans[j-1] == 'S') ans.push_back('S');
	  else ans.push_back('W');
	}
	else {
	  if(ans[j-1] == 'S') ans.push_back('W');
	  else ans.push_back('S');
	}
      }
      else {
	if(ans[j] == 'S') {
	  if(ans[j-1] == 'S')ans.push_back('W');
	  else ans.push_back('S');
	}
	else {
	  if(ans[j-1] == 'S')ans.push_back('S');
	  else ans.push_back('W');
	}
      }
    }
    bool is = false;

    if(ans[0] == ans[ans.length()-2] && ans[1] == ans[ans.length()-1])
      is = true;
    
    if(is) {
     
      cout << ans.substr(0,ans.length()-2) <<endl;
      return 0;
    }
  

  }
    
    cout <<"-1"<<endl;
}
  
