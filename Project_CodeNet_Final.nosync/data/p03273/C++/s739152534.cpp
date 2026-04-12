#include <bits/stdc++.h>
using namespace std;
long long n,m,k,h,w,ans=0,cnt=0,tmp;
int main(){
  cin >> h >> w;
  string s[h];
  bool yoko[h],tate[w];
  for(int i=0;i<w;i++){
    tate[i]=true;
  }
  for(int i=0;i<h;i++){
    yoko[i]=true;
  }
  for(int i=0;i<h;i++){
    cin >> s[i];
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        yoko[i]=false;
        break;
      }
    }
  }

  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(s[j][i]=='#'){
        tate[i]=false;
        break;
      }
    }
  }

  for(int i=0;i<h;i++){
    if(yoko[i]==true){
      continue;
    }
    cnt=0;
    for(int j=0;j<w;j++){
      if(tate[j]==false){
        cout << s[i][j];
        cnt++;
      }
    }
    if(cnt){
      cout << endl;
    }
  }
  return 0;
}
