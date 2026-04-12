#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<vector> 
#include<cstdio> 
#include<set>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{int a,b,c,x,y;
 cin>>a>>b>>c>>x>>y;
 if(x>y){
 int z=2*y;
 int half1=z*c;
 int d=x-y;
 int half2=d*a;
 int ans1=half1+half2;
 int reans1=a*x+b*y;
 int woans1=x*2*c;
 cout<<min(ans1,min(reans1,woans1))<<endl;
 }
 else if(y>x)
 {int v=2*x;
  int s1=v*c;
  int d2=y-x;
  int s2=d2*b;
  int ans2=s1+s2;
  int reans2=a*x+b*y;
  int woans2=y*2*c;
  cout<<min(ans2,min(reans2,woans2))<<endl;
  }
 else if(x==y)
 {int reans3=(a+b)*x;
  cout<<min(x*2*c,reans3)<<endl;
 }
 system("pause");
 return 0;
}