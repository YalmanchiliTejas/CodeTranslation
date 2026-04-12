#include <bits/stdc++.h>
using namespace std;

int main() {
  int t,y;
  cin >> t >> y;
  vector<vector<char>>a(t,vector<char>(y));
  for(int i=0;i<t;i++){
    for(int j=0;j<y;j++) cin >> a.at(i).at(j);
  }
  
  //横に同じのが連なった場合の処理。
  for(int i=0;i<t;i++){
    bool eq=false;
    
    for(int j=0;j<y;j++){
      if(a.at(i).at(j)=='#'){
        eq=true;
        break;
      }
    }
    
    if(eq==false){
      for(int k=i;k<t-1;k++) a.at(k)=a.at(k+1);
      for(int l=0;l<y;l++) a.at(t-1).at(l)='.';      //←a.at(t-1)=(y,'.');
      a.pop_back();         /*←やりたいのは、全て'.'の行をラストに→ラストの行削除
                               そのために一個ずつずらす。*/
      i--;                //iの位置が一個ずつずれる（はず）なのでi--する
      t--;
         }
    
  }
  
  //縦に同じのが連なった場合の処理。
  for(int j=0;j<y;j++){
    bool eq=false;
      
    for(int i=0;i<t;i++){
      if(a.at(i).at(j)=='#'){
        eq=true;
        break;
      }
    }
    
    if(eq==false){
      for(int i=0;i<t;i++){
        swap(a.at(i).at(j),a.at(i).at(y-1));
        for(int k=j;k<y-2;k++){
          swap(a.at(i).at(k),a.at(i).at(k+1));
        }
        a.at(i).pop_back();
      }
      j--;
      y--;
    }
    
  }
  
  //あとは出力！
  for(int i=0;i<t;i++){
    for(int j=0;j<y;j++){
      if(j==y-1) cout << a.at(i).at(j) << endl;
      else cout << a.at(i).at(j);
    }
  }
}