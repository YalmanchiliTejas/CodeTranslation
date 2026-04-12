#include<iostream>
using namespace std;
main(){
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
cout<<min(min(x,y)*min(a+b,c*2)+(x>y?a:b)*abs(x-y),c*2*max(x,y))<<endl;
}