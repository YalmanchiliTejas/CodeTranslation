#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int sum=a*x+b*y;
  int z=min(x,y),k=max(x,y);
  if(2*c>=a+b){
    
    cout<<sum<<endl;
  }
  else{int sum1;
       sum1=2*c*k;
    for(int i=1;i<=z;i++){
      sum+=2*c-a-b;  
    }
    cout<<min(sum,sum1)<<endl;
  }
  
  

}

