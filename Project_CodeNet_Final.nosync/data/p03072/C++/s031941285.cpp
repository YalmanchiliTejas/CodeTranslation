#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;cin>> N;
  vector<int> H;
  for (int i=0;i<N;++i){
    int h;cin>>h;H.push_back(h);
  }

  int ans=1;
  for (int i=1;i<N;++i){
    int flag=1;
    for (int j=0;j<i;++j){
      if (H[j]>H[i]){flag=0;}
    }
    if (flag==1){ans++;}
  }
  cout << ans << endl;
  return 0;
}