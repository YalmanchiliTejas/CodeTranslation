#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,m;
  cin>>n;
  string s;
  vector<int> ans(26,50),c(26,0),b;
  for(int i=0;i<n;i++){
    b=c;
    cin>>s;
    m=s.size();
    for(int j=0;j<m;j++){
      b[(int)(s[j]-'a')]++;
    }
    for(int j=0;j<26;j++){
      ans[j]=min(ans[j],b[j]);
    }
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<ans[i];j++){
      cout<<(char)(i+'a');
    }
  }
}