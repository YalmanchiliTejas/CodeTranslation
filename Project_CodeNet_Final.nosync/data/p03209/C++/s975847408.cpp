#include <bits/stdc++.h>
using namespace std;

long long runrun(long long a,long long b){
  if(a==0){return 1;}
  if(b<=1){return 0;}
  long long mon=1,mmon;
  for(int i=0;i<a;++i){
    mon*=2,mon+=3;
  }
  mmon=(mon-3)/2;
  if(mmon+1>=b){return runrun(a-1,b-1);}
  return ((long long)1<<a)+(b==2+mmon ? 0 : runrun(a-1,b-2-mmon));
}

int main(){
  long long a,b;
  cin>>a>>b;
  cout<<runrun(a,b)<<endl;
}
