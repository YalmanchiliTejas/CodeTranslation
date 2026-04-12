#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c,x,y,z,u;
  z=1000000000000;
  cin>>a>>b>>c>>x>>y;
  for(int i=0;i<max(x,y)+1;i++){
 if(i>x){
      u=2*i*c+(y-i)*b;
    }
    else if(i>y){
      u=2*i*c+(x-i)*a;
    }
    else{
      u=2*i*c+(x-i)*a+(y-i)*b;
    }
    z=min(z,u);
  }
      cout<<z<<endl;

}