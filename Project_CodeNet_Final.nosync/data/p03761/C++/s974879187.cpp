#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> A(26,50);
  for(int i=0;i<n;i++){
    string S;
    cin>>S;
    vector<int> B(26,0);
    for(char c:S)
      B[c-'a']++;
    for(int i=0;i<26;i++)
      A[i]=min(A[i],B[i]);
  }
  for(int i=0;i<26;i++)
    for(int j=0;j<A[i];j++)
      cout<<(char)(i+'a');
  cout<<endl;
}