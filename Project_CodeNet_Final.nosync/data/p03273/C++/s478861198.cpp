#include <bits/stdc++.h>
using namespace std;

int  main(){
  int H,W;
  cin>>H>>W;
  std::vector<string> v(H);
  for(int i=0;i<H;i++)cin>>v[i];
  std::vector<int> h(H,0),w(W,0);
  for(int i=0;i<H;i++){
    int a=0;
    for(int j=0;j<W;j++){
      if(v[i][j]=='#')a++;
    }
    if(a==0)h[i]++;
  }
  for(int j=0;j<W;j++){
    int a=0;
    for(int i=0;i<H;i++){
      if(v[i][j]=='#')a++;
    }
    if(a==0)w[j]++;
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(h[i]==0&&w[j]==0)cout<<v[i][j];
    }
    if(h[i]==0)cout<<endl;
  }
}
