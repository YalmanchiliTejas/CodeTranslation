#include<iostream>
#include<math.h>
using namespace std;

int main(){
 int a, b, c, x, y;
 cin>>a>>b>>c>>x>>y;
 int temp1, temp2, temp3;
 temp1 = a*x+b*y;
 temp2 = c*max(x,y)*2;
 if(x>=y)temp3 = c*y*2+a*(x-y);
 else temp3 = c*x*2+b*(y-x);
 cout<<min(min(temp1, temp2), temp3)<<endl;
}