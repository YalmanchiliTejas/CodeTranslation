
#include <bits/stdc++.h>
using namespace std;
//#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
//srandom((unsigned long)time(NULL));

long long a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
if(a+b<=2*c){
    cout<<a*x+b*y<<endl;
    return 0;
}
long long ans;
long long a1,a2,a3,a4;
if(x>=y){
    a1=c*y*2+(x-y)*a;
    a2=c*2*x;
    ans=min(a1,a2);
}else{
    a3=c*x*2+(y-x)*b;
    a4=c*2*y;
    ans=min(a3,a4);
}
cout<<ans<<endl;




return 0;
}