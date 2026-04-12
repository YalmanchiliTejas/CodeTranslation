#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,i,j;
  cin>>h>>w;
  char a[h][w],counth[h],countw[w],count=0;
  
  for(i=0;i<h;i++){
    counth[i]=0;
    for(j=0;j<w;j++){
      cin>>a[i][j];
      countw[j]=0;
    }
  }
    
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(a[i][j]=='.')
        count++;
    }
    if(count==w)
      counth[i]=1;
    count=0;
  }
    

  for(i=0;i<w;i++){
    for(j=0;j<h;j++){
      if(a[j][i]=='.')
        count++;
    }
    if(count==h)
      countw[i]=1;
    count=0;
  }
      
      for(i=0;i<h;i++){
        for(j=0;j<w;j++){
          if(counth[i]!=1 && countw[j]!=1)
            cout<<a[i][j];
        }
        if(counth[i]!=1)
          cout<<endl;
      }

}