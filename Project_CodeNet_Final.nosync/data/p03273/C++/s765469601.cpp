#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  
  vector<string> s;
  
  for(int i = 0;i < H;i++){
	string t;
    cin >> t;
    bool flag = false;
    for(int j = 0;j < W;j++){
      if(t[j] == '#'){
		flag = true;
      }
    }
    if(flag)s.push_back(t);
  }
  
  vector<int> a(W);
  
  for(int i = 0;i < s.size();i++){
    for(int j = 0;j < W;j++){
      if(s[i][j] == '#') a[j] = 1;
    }
  }
  
  for(int i = 0;i < s.size();i++){
    for(int j = 0;j < W;j++){
      if(a[j]) cout << s[i][j];
    }
    cout << endl;
  }
  
}
    
    