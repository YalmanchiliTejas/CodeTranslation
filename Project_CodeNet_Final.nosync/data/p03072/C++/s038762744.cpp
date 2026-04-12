#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,sum,Highest;
  sum=0;
  Highest=0;
  cin>>N;
  
  for(int i=0;i<N;i++){
    int H;
    cin>>H;
    if(H>=Highest){
      sum++;
      Highest=max(Highest,H);
    }else{
      sum+=0;
      Highest=Highest;
    }
  }
  cout<<sum<<endl;  
}
  
