#include <iostream>
int main(){
  int h,w;std::cin>>h>>w;
  char g[101][101];
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      std::cin >> g[i][j];
    }
  }
  int hv[101]={},wv[101]={},f;
  for(int i=0;i<h;++i){
    f=0;
    for(int j=0;j<w;++j){f=(g[i][j]=='#'?1:f);}
    hv[i]=f;
  }
  for(int i=0;i<w;++i){
    f=0;
    for(int j=0;j<h;++j){f=(g[j][i]=='#'?1:f);}
    wv[i]=f;
  }
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){if(hv[i]&wv[j]){std::cout<<g[i][j];}}
    if(hv[i]){std::cout<<"\n";}
  }
}
    