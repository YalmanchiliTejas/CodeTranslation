#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int H[N];
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  int maxH;
  maxH=H[0];
  int count=1;
  for(int i=1;i<N;i++){
    if(H[i]>=maxH){
      count++;
      maxH=H[i]; 
  }
  }
  
    cout<<count<<endl;
    return 0;
}
