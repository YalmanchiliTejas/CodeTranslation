#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  
  int k=min(d,e);

 int cnt=0;
  
int g=min(a+b,2*c);
  cnt +=k*g;
  int l=abs(d-e);
  if(d>=e){
  if(a >=2*c){
  cnt +=l*2*c;
  
  }
   else{
   cnt +=l*a;}
  }
  else{
    if(b >=2*c)cnt +=l*2*c;
  else{cnt += l*b;}
}
  cout <<cnt <<endl;
}