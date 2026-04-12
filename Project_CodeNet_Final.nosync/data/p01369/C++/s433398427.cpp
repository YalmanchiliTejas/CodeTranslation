#include <bits/stdc++.h>
using namespace std;

#define PI 4*atan(1)
#define INF 1e8

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


bool check(char c){
  string left = "qazwsxedcrfvtgb";
  string right = "yhnujmiklop";
  for(int i = 0; i < left.size(); i++){
    if(left[i] == c)return true;
  }
  return false;
}

int main(){
  string s;
  while(cin >> s, s != "#"){
    int cnt = 0;
    bool flag = check(s[0]);
    for(int i = 1; i < s.size(); i++){
      bool f = check(s[i]);
      if(flag != f)cnt++;
      flag = f;
    }
    cout << cnt << endl;
  }
}