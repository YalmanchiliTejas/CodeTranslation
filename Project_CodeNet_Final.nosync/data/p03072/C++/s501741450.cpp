#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,k=0,l=0;
  cin>>N;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    if(j>=k){
      l++;
      k=j;
    }
  }
  cout<<l<<endl;
}