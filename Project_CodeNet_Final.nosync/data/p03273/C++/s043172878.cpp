#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int h,w;
  cin>>h>>w;
  char a[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  //横方向に探索
  for(int i=0;i<h;i++){
    if(a[i][0]=='.'&&a[i][w-1]=='.'){
      for(int j=1;j<w-1;j++){
        if(a[i][j]=='#')  break;
        if(j==w-2){
          for(int k=0;k<w;k++){
            a[i][k]='*';
          }
        }
      }
    }
  }

  //縦方向に探索
  for(int i=0;i<w;i++){
    if(a[0][i]!='#'&&a[h-1][i]!='#'){
      for(int j=1;j<h-1;j++){
        if(a[j][i]=='#')  break;
        if(j==h-2){
          for(int k=0;k<h;k++){
            a[k][i]='*';
          }
        }
      }
    }
  }

// //debug:一回全部表示させてみる
//   for(int i=0;i<h;i++){
//     for(int j=0;j<w;j++){
//       cout<<a[i][j];
//     }
//     cout<<endl;
//   }

  //0以外を出力
  bool flag=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]!='*'){
        cout<<a[i][j];
        flag=1;
      }
    }
    if(flag){
      cout<<endl;
      flag=0;
    }
  }
  return 0;
}
