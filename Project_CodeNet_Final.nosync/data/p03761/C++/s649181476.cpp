#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
map<char,int>m[n];
string S[n];
rep(i,n){
  cin>>S[i];
  rep(j,S[i].size()){
    m[i][S[i][j]]++;
  }
}
vector<char> ans;
for(char i='a';i<='z';i++){
    int count=m[0][i];
for(int k=1;k<n;k++){
count=min(count,m[k][i]);
}
if(count){
  for(int q=0;q<count;q++){
    ans.push_back(i);
  }
}
}
rep(i,ans.size()){
  cout<<ans[i];
}

  return 0;
}
