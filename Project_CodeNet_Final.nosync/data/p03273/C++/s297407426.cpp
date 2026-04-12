#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long X=1000000000+7;

int main() {
  int h,w;
  cin>>h>>w;
  string dot="";
  rep(i,w) dot+='.';
  vector<string> A;
  rep(i,h){
    string s;
    cin>>s;
    if(s!=dot){
      A.push_back(s);
      //cout<<i<<s<<endl;
    }
  }
  vector<int> num;
  rep(i,w){
    bool exist=true;
    rep(j,A.size()){
      if(A[j][i]!='.'){
        exist=false;
        //cout<<j<<i;
        break;
      }
    }
    if(exist) num.push_back(i);
  }
  
  rep(i,A.size()){
    rep(j,w){
      if(count(num.begin(),num.end(),j)==0)
        cout<<A[i][j];
    }
    cout<<endl;
  }
}