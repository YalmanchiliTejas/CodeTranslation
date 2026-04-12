#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w; //flag=1の時、一致している状態。loop中にflag=0となったらすぐにbreakする。
  cin >> h >> w;
  int flag1=0;
  vector<int> flag2(w,0); //縦の重複
  vector<string> lines(h);
  //入力
  for(int i=0;i<h;i++){
    cin >> lines.at(i);
  }
  //縦の重複の判断
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(lines.at(j).at(i)=='.')flag1=1;
      else{
      	flag1=0;
      	break;
      }
    }
    if(flag1==1)flag2.at(i)=1;
    flag1=0;
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(lines.at(i).at(j)!='.'){
      	flag1=0;
        break;
      }
      else flag1=1;
    }
    //出力フェーズ
    if(flag1!=1){
      for(int j=0;j<w;j++){
        if(flag2.at(j)!=1)cout << lines.at(i).at(j);
      }
    }
    flag1=0;
    cout << endl;
  }
}