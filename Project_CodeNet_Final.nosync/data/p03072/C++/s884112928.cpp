#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,a;
  cin>>N;
  a=0;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin>>H.at(i);}
  
  for(int i=N-1;i>0;i--){int x=0;
   for(int j=0;j<i;j++){
     if(H.at(i)>=H.at(j)){x++;}
   }
    if(x==i){a++;}
  }
  cout<<a+1<<endl;
}