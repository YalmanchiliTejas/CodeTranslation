//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>>vvi;


int main(){
  int h,w;
  cin>>h>>w;
  char field[110][110];
  vector<bool>gyo(h,false);
  vector<bool>retu(w,false);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>field[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(field[i][j]=='#')gyo[i]=true;
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(field[i][j]=='#')retu[j]=true;
    }
  }
  for(int i=0;i<h;i++){
    if(gyo[i]){
      for(int j=0;j<w;j++){
        if(retu[j])cout<<field[i][j];
      }
      cout<<endl;
    }
  }
}