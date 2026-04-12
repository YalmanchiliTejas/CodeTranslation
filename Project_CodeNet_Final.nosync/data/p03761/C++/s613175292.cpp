#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<string>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  string ans="";
  for(char i='a';i<='z';i++){
  int Min=50;
    for(int j=0;j<N;j++){
    int M=0;
      int n=A.at(j).size();
       
      for(int k=0;k<n;k++)
       if(A.at(j).at(k)==i)
         M++;
      
      if(M<Min) Min=M;
    } for(int l=0;l<Min;l++)
      ans+=i;
  
  }cout<<ans<<endl;
    return 0;
}