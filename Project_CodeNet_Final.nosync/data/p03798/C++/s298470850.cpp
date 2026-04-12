#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,j,k;
  string s;
  cin>>n>>s;
  vector<int> x(n+1);
  for(j=1;j<=n;j++){
    if(s.at(j-1)=='o') x.at(j)=1;
    else if(s.at(j-1)=='x') x.at(j)=-1;
  }
  vector<int> s1_={1,1,-1,-1};
  vector<int> s2_={1,-1,1,-1};
  for(k=0;k<4;k++){
    vector<int> y(n+1);
    y.at(1)=s1_.at(k);
    y.at(2)=s2_.at(k);
    y.at(0)=y.at(2)*y.at(1)*x.at(1);
    for(j=3;j<=n;j++) y.at(j)=y.at(j-2)*y.at(j-1)*x.at(j-1);
    if(y.at(0)==y.at(n)&&y.at(1)==y.at(n-1)*y.at(n)*x.at(n)){
      for(j=1;j<=n;j++){
        if(y.at(j)==1) cout<<'S';
        else if(y.at(j)==-1) cout<<'W';
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}