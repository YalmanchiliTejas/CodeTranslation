#include<iostream>
using namespace std;

int main(){
  char c;
  int cnt=0,h,w; cin>>h>>w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c;
      if(c=='#')cnt++;
    }
  }
  cout<<(cnt==h+w-1 ? "Possible" : "Impossible")<<endl;
  return 0;
}
