#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)

int H,W;
char a[10][10],b[10][10];
string s;

int main(){
  cin >> H >> W;

  rep(i,H){
    rep(j,W){
      cin >> a[i][j];
    }
  }

  rep(i,H-1){
    s += "d";
  }
  rep(i,W-1){
    s += "r";
  }

  do{
    //初期化
    rep(i,H){
      rep(j,W){
        if((i==0&&j==0)){
          b[i][j] = '#';
        }else{
          b[i][j] = '.';
        }
      }
    }

    int px=0,py=0;
    //sに従って順路を作る
    rep(i,H+W-2){
      if(s[i] == 'd'){
        py++;
      }else{
        px++;
      }
      b[py][px]='#';
    }

    //一致しているかどうか判定
    bool pos=true;
    rep(i,H){
      rep(j,W){
        if(a[i][j] != b[i][j]){
          pos = false;
          i=j=INF;
        }
      }
    }

    if(pos){
      cout << "Possible" << endl;
      return 0;
    }
    
    /*rep(i,H){
      rep(j,W){
        cout << b[i][j];
      }
      cout << endl;
    }*/
    //cout << s << endl;
  }while(next_permutation(all(s)));
  cout << "Impossible" << endl;
}