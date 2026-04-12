#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,a,input=0,output=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    if(a==(input= max(input,a))){
      output++;
    }
       }
  cout<<output;
}