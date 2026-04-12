
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()

{
  long n,x,y,z,m;
  cin>>n;

  if(n%15==0)
    cout<<(n*800)-200*(n/15)<<endl;
  else{
    x=n/15;
    z=x*15;
    y=n-z;
    m=((z*800)-(200*x))+y*800;
    cout<<m<<endl;


  }
 return 0;
}






