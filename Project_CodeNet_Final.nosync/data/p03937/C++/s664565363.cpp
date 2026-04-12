#include<bits/stdc++.h>
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
using namespace std;
int main(){
  int h,w;
  int count=0;
  cin>>h>>w;
  char n[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>n[i][j];
      if(n[i][j]=='#')
        count++;
    }
  }
  if(count==(h+w-1))
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;
}