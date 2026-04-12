#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  int k=0;
  std::vector<string> v(h);
  int a=0;
  for(int i=0;i<h;i++)cin>>v[i];
  int i=0;
  int j=0;
  while(k==0){
    v[i][j]='.';
    if(i<h-1){
      if(j<w-1){
        if(v[i+1][j]=='#'){i++;continue;}
        if(v[i][j+1]=='#'){j++;continue;}
      }
      else{
        if(v[i+1][j]=='#'){i++;continue;}
      }
    }
    else{
      if(v[i][j+1]=='#'){j++;continue;}
    }
    a++;
    if(a>1000)break;
  }
  for(i=0;i<h;i++)for(j=0;j<w;j++)if(v[i][j]=='#')k++;
  if(k)cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;
}
