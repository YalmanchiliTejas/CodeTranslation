#include <bits/stdc++.h>

using namespace std;
int main() {
int64_t a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int r=min(d,e);
  int64_t t=100000000000;
  for(int i=0;i<r+1;i++)
 {
  int64_t g=c*i*2+(d-i)*a+(e-i)*b;
  t=min(t,g);
    
}
  if(d>e){
   for(int i=r+1;i<d+1;i++)
 {
  int64_t g=c*i*2+(d-i)*a;
  t=min(t,g);
     
}
  }
  else{
       for(int i=r+1;i<e+1;i++)
 {
  int64_t g=c*i*2+(e-i)*b;
  t=min(t,g);
}
  
  }
cout<<t;
}

