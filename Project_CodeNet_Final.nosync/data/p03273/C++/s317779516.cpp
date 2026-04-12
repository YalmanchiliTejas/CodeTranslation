#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b;
  cin>>a>>b;
  vector<bool>vec(a,false);
  vector<bool>veco(b,false);
  vector<vector<char>>vec1(a,vector<char>(b));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      cin>>vec1.at(i).at(j);
      if(vec1.at(i).at(j)=='#'){
        vec.at(i)=true;
        veco.at(j)=true;
      }
    }
  }
  for(int i=0;i<a;i++){
    if(vec.at(i)){
      for(int j=0;j<b;j++){
        if(veco.at(j)){
          cout<<vec1.at(i).at(j);
        }
      }
      cout<<endl;
    }
  }
  return 0;
}
