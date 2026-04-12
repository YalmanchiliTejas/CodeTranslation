#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int X,Y,Z;

cin>>X>>Y>>Z;

for(int i=0;i<X;i++){
  if(X-Y*i-Z*(i+1)<0){
    cout<<i-1<<endl;
    break;
  }
}
}

    
    