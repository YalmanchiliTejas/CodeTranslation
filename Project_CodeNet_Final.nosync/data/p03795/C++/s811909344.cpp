#include<bits/stdc++.h>
using namespace std;
main(){
  const int N=[]{int x;cin>>x;return x;}();
  const int x=[N]{
    int x=0;
    for(int i=1;i<=N;++i)x+=800;
    return x;
  }();
  const int y=[N]{
    int y=0;
    for(int i=1;i<=N;++i)if(i%15==0)y+=200;
    return y;
  }();
  cout<<(x-y)<<endl;
}
