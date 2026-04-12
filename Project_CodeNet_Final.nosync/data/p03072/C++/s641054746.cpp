#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
  cin>>N;
  vector<int>H(N);
  for(int i=0; i<N; i++){
   cin>>H[i];}
  
  int count=0;
  for(int i=N-1; i>=0; i--){
    bool flag=true;
   for(int j=0; j<i; j++){
    if(H[i]<H[j]){flag=false;}
   }
    if(flag){count++;}
  }

  cout<<count;
}
