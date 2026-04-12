#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int vec[n][26]={};
  
  vector<string>S(n);
  for(int i=0;i<n;i++){
    cin>>S[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<S[i].size();j++){
      for(char k='a';k<='z';k++){
        if(S[i][j]==k) vec[i][k-'a']++;
      }
    }
  }
  vector<int> ans(26);
  for(int j=0;j<26;j++){
    int min=vec[0][j];
    for(int i=0;i<n;i++){
      min=(vec[i][j]>min)?min:vec[i][j];
    }
    ans[j]=min;
  }
  vector<char> str;
  for(int j=0;j<26;j++){
    for(int i=0;i<ans[j];i++){
      str.push_back('a'+j);
    }
  }
  
  for(auto &e:str){
    cout<<e;
  }
}