#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<n;i++)
#define test(a) cout << "*" << a << endl
int main (){
  int h,w;
  char a[100][100];
  int i,j;
  bool nonexistH[100] = {};
  bool nonexistW[100] = {};
  
  cin >> h >> w;
  
  rep(i,0,h){
    rep(j,0,w){
      cin >> a[i][j];
    }
  }  
  /*rep(i,0,h){
    rep(j,0,w){
      cout << a[i][j];
    }
    cout << endl;
  }*/
  
  rep(i,0,h){
    rep(j,0,w){
      if(a[i][j]=='#'){
        nonexistH[i] = true;
        break;
        
      }
    }
  }
  //test("*");
  //rep(i,0,h) test(nonexistH[i]);
  
  rep(j,0,w){
    rep(i,0,h){
      if(a[i][j]=='#'){
        nonexistW[j] = true;
        //test(j);
        break;
        
      }
    }
  }
  //test("*");
  //rep(j,0,w) test(nonexistW[j]);
  
  rep(i,0,h){
    if(nonexistH[i]==false)
      continue;
    else{
      rep(j,0,w){
        if(nonexistW[j]==false)
          continue;
        else{
          cout << a[i][j];  
        }
      }
    }
    cout << endl;
  }
          
 
}