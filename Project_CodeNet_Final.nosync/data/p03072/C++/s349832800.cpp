#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    bool flg=false;
    for(int j=0;j<i;j++){
      if(a.at(j)>a.at(i)){
        flg=true;
      }
      if(flg){
        break;
      }
    }
    if(!flg){
      ans++;
    }else{
      flg=false;
    }
  }
  cout << ans << endl;
}