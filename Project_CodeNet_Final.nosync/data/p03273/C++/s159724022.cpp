#include <iostream>
#include <string>
using namespace std;
int h,w;
int H,W;
string s[109];
string S;
bool flag;
int main() {
  cin >> H>> W;
  h=0;
  w=W;

  for(int i=0;i<H;i++){
    cin >> S;
    flag=false;
    for (int j=0;j<W;j++){
      if(S.substr(j,1)=="#"){
        flag=true;
      }
    }
    if(flag){
      s[h]=S;
      h++;
    }
  }
  for(int i=W-1;i>=0;i--){
    flag=true;
    for(int j=0;j<h;j++){
      if(s[j].substr(i,1)=="#"){
        flag=false;
      }
    }
    if(flag){
      for(int k=0;k<h;k++){
        s[k].erase(i,1);
      }
    }
  }
  for(int i=0;i<h;i++){
    cout << s[i] << "\n";
  }
}