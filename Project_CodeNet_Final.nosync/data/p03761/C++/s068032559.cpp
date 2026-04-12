#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i,r,j,nu,k;
  cin >> n;
  vector<string> s(n);
  map<char,int> mp;
  vector<int> ans(26,100);
  for(i=0;i<n;++i){
    cin >> s[i];
    int a[30] ={0};
    for(j=0;j<s[i].size();++j){
      int x=s[i][j]-'a';
      a[x]++;
    }
    for(j=0;j<26;++j){
      ans[j]=min(ans[j],a[j]);
    }
  }
  string anss;
  for(i=0;i<26;++i){
    char z=i+97;
    if(ans[i]>0 && ans[i]!=100){
      r=0;
      while(r<ans[i]){
        anss=anss+z;
        r++;
      }
    }
  }
  cout << anss << endl;
  return 0;



}
