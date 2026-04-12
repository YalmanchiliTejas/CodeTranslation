#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i,j,k;
  int a,m,n,o,p,q,s,t,u;
  double r;
  cin>>m;
  for(i=0;i<m;i++){
    cin>>p>>n>>o;
    a=0;
    for(j=0;j<o;j++){
      cin>>q>>r>>s;
      t=p;
      if(q){
	for(k=0;k<n;k++){
	  t+=(int)(t*r);
	  t-=s;
	}
	a=max(a,t);
      }else{
	u=0;
	for(k=0;k<n;k++){
	  u+=(int)(t*r);
	  t-=s;
	}
	a=max(a,t+u);
      }
    }
    cout<<a<<endl;
  }
  return 0;
}