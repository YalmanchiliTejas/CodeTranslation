#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
using ll = long long;
using VI = vector<int>;

int main(){
  int h,w;cin >> h >> w;
  char a[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  for(int j=0;j<w;j++){
    bool flag=true;
    for(int i=0;i<h;i++){
      if(a[i][j]=='#') flag = false;
    }
    if(flag){
        for(int i=0;i<h;i++){
          a[i][j]='a';
        }
    }
  }
  for(int i=0;i<h;i++){
    bool flag = true;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#') flag = false;
    }
    if(flag){
      for(int j=0;j<w;j++){
        a[i][j]='a';
      }
    }
  }
  //cout << endl << endl << endl;
  for(int i=0;i<h;i++){
    bool flag = false;
    for(int j=0;j<w;j++){
      if(a[i][j]!='a'){
        cout << a[i][j];
        flag = true;
      }
    }
    if(flag) cout << endl;
  }

}
