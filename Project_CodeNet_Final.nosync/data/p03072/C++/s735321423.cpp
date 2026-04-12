#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  vector<int> H;
  int ans=0; int mh=0;
  for(int i=0;i<N;i++){
    int h; cin>>h;
    if(mh<=h){ mh=h; ans++; }
  }
  cout<<ans<<endl;
  return 0;
}