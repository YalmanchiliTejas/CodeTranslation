#include <bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    string s;
  cin >> s;
  if(s[0]=='#')break;
  string left = "qwertasdfgzxcvb";
  int ans = 0;
  for(int i=1;i<s.size();i++){
    bool flag[2]={false, false};
    for(int j=0;j<left.size();j++){
      if(s[i] == left[j])flag[0] = true;
      if(s[i-1] == left[j])flag[1] = true;
    }
    if(flag[0] ^ flag[1])ans++;
  }
  printf("%d\n", ans);
  }
  return 0;
}

