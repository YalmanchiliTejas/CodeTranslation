#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main() {

int H,W;
  cin>>H>>W;
  vector<string> A(H);
  for(int i=0;i<H;i++){
    cin>>A.at(i);}

  for(int j=0;j<A.size();j++){
  for(int i=0;i<W;i++){
    if(A.at(j).at(i)=='#')break;
    else if (i==W-1){A.erase(A.begin()+j);j--;}
  }
  }


  for(int j=0;j<A.at(0).size();j++){
  for(int i=0;i<A.size();i++){
    if(A.at(i).at(j)=='#')break;
    if (i==A.size()-1){
      for(int k=0;k<A.size();k++){
      A.at(k).erase(A.at(k).begin()+j);}j--;}
  }
  }

      for(int i=0;i<A.size();i++){
    cout<<A.at(i)<<endl;}
}