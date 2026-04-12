#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y,smaller,bigger,fewer,much,presume_a,presume_b;
  cin>>a>>b>>c>>x>>y;
  if(x<y){
  smaller=x;
  bigger=y;
  fewer=a;
  much=b;
  }else{
  smaller=y;
  bigger=x;
  fewer=b;
  much=a;
  }
  if(a+b<=c*2)cout<<a*x+b*y<<endl;
  if(a+b>c*2){
    presume_a=c*2*smaller+(bigger-smaller)*much;
    presume_b=c*2*bigger;
    cout<<min(presume_a,presume_b)<<endl;
  }
}