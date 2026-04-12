#include<iostream>
#include<vector>
using namespace std ;

int main()
{
  int H,W ;
  cin>>H>>W ;
  vector<vector<char>>a(H,vector<char>(W)) ;
  for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>a.at(i).at(j) ;
  
  int flag1=0 ;  //一列が白のみのとき、flag1=0
  int flag2=0 ;  //一行が白のみのとき、flag2=0
  /*i(0<=i<H)列を固定して、j行が白のみか判定*/
  for(int i=0;i<H;i++){
    
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)=='#'){
        flag1=1 ;
        break ;
      }
    }
    
    if(flag1==0){
      H-- ;
      for(int k=0;k<W;k++){
        for(int l=i;l<H;l++) a.at(l).at(k)=a.at(l+1).at(k) ;
      }
      i=-1 ;
    }
    flag1=0 ;
  }
  
  /*i(0<=i<W-1)行を固定して、j列を白のみか判定*/
  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(a.at(j).at(i)=='#'){
        flag2=1 ;
        break ;
      }
    }

    
    if(flag2==0){
      W-- ;
      for(int k=0;k<H;k++){
        for(int l=i;l<W;l++) a.at(k).at(l)=a.at(k).at(l+1) ;
      }
      i=-1 ;
    }
    flag2=0 ;
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<a.at(i).at(j) ;
      if(j==W-1) cout<<endl ;
    }
  }

  return 0 ;
}