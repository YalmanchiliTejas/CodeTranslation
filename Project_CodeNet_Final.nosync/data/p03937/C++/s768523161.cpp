#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,k=0;
  cin>>H>>W;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      char c;
      cin>>c;
      if(c=='#')
        k++;
    }
  if(k==H+W-1)
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;
}