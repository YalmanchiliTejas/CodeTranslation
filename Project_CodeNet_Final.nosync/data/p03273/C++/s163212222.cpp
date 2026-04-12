#include<iostream>
#include<string>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  char a[H+1][W+1];
  for(int i=0;i<H;i++){
    for(int k=0;k<W;k++){
      cin>>a[i][k];
    }
  }
  char ans[H+1][W+1];
  int countr=0;
  int countc=0;
  for(int i=0;i<H;i++){
    int juge=0;
    for(int k=0;k<W;k++){
      if(a[i][k]=='#'){
        juge=1;
      }
    }
    //cout<<juge<<endl;
    if(juge==1){
      for(int h=0;h<W;h++){
        ans[countr][h]=a[i][h];
        //cout<<ans[countr][h]<<endl;
      }
      countr++;
    }
  }
  char answ[H+1][W+1];
  for(int k=0;k<W;k++){
    int juge=0;
    for(int i=0;i<countr;i++){
      if(ans[i][k]=='#'){
        juge=1;
      }
    }
    if(juge==1){
      for(int h=0;h<countr;h++){
        answ[h][countc]=ans[h][k];
      }
      countc++;
    }
  }
  for(int i=0;i<countr;i++){
    for(int k=0;k<countc;k++){
      cout<<answ[i][k];
    }
    cout<<endl;

  }

return 0;
}
