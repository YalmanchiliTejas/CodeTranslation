#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define ll long long
 
//const int INF = 1e8;
typedef pair<int,int>P;
int dx[4] = {1,0,-1,0};int dy[4] = {0,1,0,-1};
queue<P> que;

int main(void){
  int h,w;cin >> h >> w;cin.ignore();
  bool frag[w+1][h+1];
  char m[w+1][h+1];
  for(int i = 0;i<h;i++){
    string s;getline(cin,s);
    for(int j = 0;j<w;j++){
      m[j][i] = s.at(j);
      frag[j][i] = false;
    }
  }
  for(int i = 0;i<h;i++){
    bool tmp = true;
    for(int j = 0;j<w;j++){
      if(m[j][i] == '#') tmp = false;
    }
    if(tmp == true) {
      for(int k = 0;k<w;k++)frag[k][i] = true;
    }
  }
  for(int i = 0;i<w;i++){
    bool tmp = true;
    for(int j = 0;j<h;j++){
      if(m[i][j] == '#') tmp = false;
    }
    if(tmp == true){
      for(int k = 0;k<h;k++)frag[i][k] = true;
    }
  }
  for(int i = 0;i<h;i++){
    bool tmp = false;
    for(int  j = 0;j<w;j++){
      if(frag[j][i] == false){
        cout << m[j][i];
        tmp = true;
      }
    }
    if(tmp == true) cout << endl;
  }
  /*for(int i = 0;i<h;i++){
    for(int  j = 0;j<w;j++){
      if(frag[j][i] == false){
        cout << 0 << " ";
      }else{
        cout << 1 << " ";
      }
    }
    cout << endl;
  }
  */
}