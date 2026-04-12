#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w,c=0;
  cin>>h>>w;
  char s[h+1][w+1];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='#')
        c++;
    }
  }
  if(s[0][0]!='#'||s[h-1][w-1]!='#'){
    cout<<"Impossible";
    return 0;
  }
  int i=0,j=0,k=1;
  while(i!=h-1||j!=w-1){
    if(s[i+1][j]=='#'){
      i++;
      k++;
    }else if(s[i][j+1]=='#'){
      j++;
      k++;
    }else{
      cout<<"Impossible";
      return 0;
    }
  }
  cout<<(c==k?"Possible":"Impossible");
}
