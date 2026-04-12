#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<vector<int>> vec(N, vector<int>(26)); 
  for(int i=0;i<N;i++){
    string S;
    cin>>S;
    for(int j=0;j<S.size();j++){
      vec.at(i).at(S.at(j)-97)+=1;
    }
  }
  vector<int> kaz(26);
  for(int i=0;i<26;i++){
    int mi=100;
    for(int j=0;j<N;j++){
      mi=min(mi,vec.at(j).at(i));
    }
    kaz.at(i)=mi;
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<kaz.at(i);j++){
      cout<<char(i+97);
    }
  }
  cout<<endl;
      
    
  
  
  
}