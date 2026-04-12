#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,m,x=1,h;cin>>N;
  cin>>m;
  for(int i=1;i<N;i++){
    cin>>h;
    if(h>=m){
      x++;m=h;
    }
  }
  cout<<x<<endl;
}