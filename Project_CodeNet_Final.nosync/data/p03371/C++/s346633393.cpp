#include<bits/stdc++.h>
using namespace std;
#define inf 4294967295
int main(){
  long long a,b,c,x,y,ans=inf;
  cin>>a>>b>>c>>x>>y;
  long long r[3],p[3],e[3];
  if(x>y){
    r[0]=y*2*c+(x-y)*a;
    r[1]=x*2*c;
    r[2]=x*a+y*b;
    for(int i=0;i<3;i++)
        ans=min(ans,r[i]);
    }
  if(x<y){
    p[0]=x*2*c+(y-x)*b;
    p[1]=y*2*c;
    p[2]=x*a+y*b;
    for(int i=0;i<3;i++)
    ans=min(ans,p[i]);


  }
  if(x==y){
    e[0]=x*2*c;
    e[1]=x*a+b*y;
    ans=min(e[0],e[1]);}

cout<<ans;



return 0;
}