#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<N;i++)
int main(){
  int H,W;
  cin>>H>>W;
  int cnt=0;
  rep(i,H){
    rep(j,W){
      char a; cin>>a;
      if(a=='#') cnt++;
    }
  }
  if(cnt == H+W-1) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}
