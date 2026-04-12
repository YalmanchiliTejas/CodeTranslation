#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  //白いマスのみからなる行または列が存在する間、次の操作を繰り返し行います
  //操作: 白いマスのみからなる行または列をひとつ任意に選び、その行または列を取り除いて空白を詰める。
  vector<string> c(h);
  for(int i=0;i<h;i++){
    cin>>c[i];
  }

  vector<bool>row(h,false);//falseで初期化
  vector<bool>col(w,false);//falseで初期化
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(c[i][j]=='#'){
        row[i]=true;
        col[j]=true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(row[i]){
      for(int j=0;j<w;j++){
        if(col[j]){
          cout<<c[i][j];
        }
      }
    }
    cout<<endl;
  }
}
