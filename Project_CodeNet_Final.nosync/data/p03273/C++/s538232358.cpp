#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin>>a.at(i).at(j);
    }
  }

  vector<int> t(h),y(w);


  for(int j=0;j<h;j++){
    for(int i=0; i<w; i++){
    if(a.at(j).at(i)=='#'){
      t[j]=1;
    }
   }
  }

  for(int i=0;i<w;i++){
    for(int j=0; j<h; j++){
    if(a.at(j).at(i)=='#'){
      y[i]=1;
    }
   }
  }

  /**/
  /*for(int i=0;i<w;i++){
    cout<<y[i];
  }
  cout<<endl;

  for(int i=0;i<h;i++){
    cout<<t[i];
  }
  cout<<endl;*/


  for(int j=0;j<h;j++){
    for(int i=0;i<w; i++){
      if(t[j]!=0 && y[i]!=0){
        cout<<a.at(j).at(i);
      }
    }
    if(t[j]!=0){
      cout<<endl;
    }
    
  }


  
  
}
