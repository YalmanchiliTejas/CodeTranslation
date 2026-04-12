#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int h,w;
  cin >> h >> w;
  char a[h][w];
  int tate[w]={0},yoko[h]={0};
  rep(i,h)rep(j,w){
    cin >> a[i][j];
    if(a[i][j]=='#')tate[j]=1;
    if(a[i][j]=='#')yoko[i]=1;
  }

  rep(i,h){
    rep(j,w){
      if(yoko[i]==1 && tate[j]==1){
        cout << a[i][j];
      }
    }
    if(yoko[i]==1)cout << endl;
  }

}

/*
愚直に消していく手段が思いつかなかったので解説を読んだ
>> まず，黒いマスが含まれる行および列をマークします．
>> その後，マークされた行とマークされた列が交差する位置の ai,j のみを出力すればよいです．
天才か？？？？？
*/