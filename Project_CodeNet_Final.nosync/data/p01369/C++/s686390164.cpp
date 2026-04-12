#include <bits/stdc++.h>
using namespace std;

string s;
bool rl[26]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};
bool now;
int cnt;

int main(){
  int i;
  while(1){
    cin >> s;
    if(s=="#")break;
    cnt=0;
    now = rl[s[0]-'a'];
    for(i=1;i<s.size();i++){
      if(now!=rl[s[i]-'a']){
	cnt++;
	now = rl[s[i]-'a'];
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

