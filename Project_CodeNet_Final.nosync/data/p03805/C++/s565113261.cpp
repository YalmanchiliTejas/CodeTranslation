#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>&a,vector<int>b,int i,int n){
  int counter=0;
  for(int k;k<n+1;k++){
    counter+=b.at(k);
  }
  if(b.at(i)==0&&counter==n-1){
    return 1;
  }
  if(b.at(i)==0){
    b.at(i)=1;
    int sum=0;
    for(int j=0;j<a.at(i).size();j++){
      sum+=dfs(a,b,a.at(i).at(j),n);
    }
    return sum;
  }
  else return 0;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  vector<int> b(m);
  for(int i=0;i<m;i++){
    cin>>a.at(i)>>b.at(i);
  }
  vector<vector<int>> c(n+1);
  for(int i=0;i<m;i++){
    c.at(a.at(i)).push_back(b.at(i));
    c.at(b.at(i)).push_back(a.at(i));
  }
  vector<int> f(n+1);
  cout<<dfs(c,f,1,n)<<endl;
}