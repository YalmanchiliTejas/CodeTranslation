#include<bits/stdc++.h>
using namespace std;
bool a[101][101];
int H,W;
main(){
  cin>>H>>W;
  for(int h=1;h<=H;++h){
    for(int w=1;w<=W;++w){
      char c;
      cin>>c;
      a[h][w]=c=='#';
    }
  }
  for(int h=1;h<=H;++h){
    for(int w=1;w<=W;++w){
      bool exists_col=false;
      bool exists_row=false;
      for(int h2=1;h2<=H;++h2)if(a[h2][w])exists_col=true;
      for(int w2=1;w2<=W;++w2)if(a[h][w2])exists_row=true;
      if(exists_col&&exists_row){
        cout<<(a[h][w]?'#':'.');
      }
    }
    bool exists_row=false;
    for(int w2=1;w2<=W;++w2)if(a[h][w2])exists_row=true;
    if(exists_row)cout<<endl;
  }
}
