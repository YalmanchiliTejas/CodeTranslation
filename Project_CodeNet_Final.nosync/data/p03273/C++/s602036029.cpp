#include <iostream>
#include <string>
using namespace std;
int main(){
  int h,w;
  cin >> h>>w;
  string s[h];
string c;
  for(int i=0;i<h;i++){
      cin >> s[i];
  }
  int r[h];
  for(int i=0;i<h;i++) r[i]=-1;
  for(int i=0;i<h;i++){
    bool flag=true;
    for(int j=0;j<w;j++){
      if(s[i][j]!='.') flag=false;
    }
    if(flag) r[i]=1;
  }
  int wi[w];
  bool flag;
  for(int i=0;i<w;i++) wi[i]=-1;
  for(int i=0;i<w;i++){
    flag=true;
    for(int j=0;j<h;j++){
      if(s[j][i]!='.') flag=false;
    }
    if(flag) wi[i]=1;
  }
  //for(int i=0;i<h;i++) cout << r[i];
  flag=false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(r[i]==-1&&wi[j]==-1){
        cout<< s[i][j];
        flag=true;
      }
    }
    if(flag) cout << endl;
    flag=false;
  }
}
