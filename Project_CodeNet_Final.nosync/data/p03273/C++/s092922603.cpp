#include <bits/stdc++.h>
using namespace std;
#define fol(i,n) for(int i=0;i<n;++i)
bool vecfind(vector<int> A,int n){
  bool flag = false;
  int k = A.size();
  fol(i,k){
    if(A[i]==n)flag = true;
  }
  return flag;
}
int main(){
  int h,w;cin>>h>>w;
  string s[h];
  fol(i,h){
    cin>>s[i];
  }
  vector<int> a,b;
  fol(i,h){
    bool is = true;
    fol(j,w){
      if(s[i][j]=='#')is=false;
    }
    if(is)a.push_back(i);
  }
  fol(i,w){
    bool is = true;
    fol(j,h){
      if(s[j][i]=='#')is = false;
    }
    if(is)b.push_back(i);
  }
  fol(i,h){
    if(vecfind(a,i))continue;
    fol(j,w){
      if(vecfind(b,j))continue;
      cout << s[i][j];
    }
    cout << endl;
  }
  return 0;
}
