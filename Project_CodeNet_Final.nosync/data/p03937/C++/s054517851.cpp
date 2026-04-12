#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> A(H+2,vector<char>(W+2,'.'));
  int counter=0;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin>>A.at(i).at(j);
      if(A.at(i).at(j)=='#'){
        counter++;
      }
    }
  }
  if(counter==H+W-1){
    cout<<"Possible"<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }
}
