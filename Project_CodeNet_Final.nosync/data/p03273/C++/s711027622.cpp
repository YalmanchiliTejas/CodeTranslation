#include <bits/stdc++.h>
using namespace std;

int main() {
int h,w;
cin>>h>>w;
char g[h][w];
int eh[h],ew[w];
for(int i=0;i<h;i++){
  for(int j=0;j<w;j++) cin>>g[i][j];
}

for(int j=0;j<h;j++) eh[j]=0;
for(int j=0;j<w;j++) ew[j]=0;

for(int i=0;i<h;i++){
  int c=0;
  for(int j=0;j<w;j++) if(g[i][j]=='.') c++;
  if(c==w) eh[i]=1;
}

for(int i=0;i<w;i++){
  int c=0;
  for(int j=0;j<h;j++) if(g[j][i]=='.') c++;
  if(c==h) ew[i]=1;
}

for(int i=0;i<h;i++){
  for(int j=0;j<w;j++) {
    if(eh[i]==0&&ew[j]==0) cout<<g[i][j];
  }
  if(eh[i]==0) cout<<endl;
}

}
