#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  
  for(int i = 0; i < (int)s.size() - 1; i++){
      for(int j = i + 1; j < (int)s.size(); j++){
	      if(s[i] != s[j]){
		      cout << "Yes" << "\n";
		      return 0;
		  }
	  }
  }
  cout << "No" << "\n";
  return 0;
}
