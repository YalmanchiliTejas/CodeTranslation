#include<iostream>
#include<algorithm>
#include<string> 
#include<map>
#include<set>
#include<vector>
#include<string.h> 
#include<math.h>
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{int a,b,c,x,y,m;cin>>a>>b>>c>>x>>y;
int n=c*2*max(x,y);
if(x>y) m=(x-y)*a+y*2*c;
else m=(y-x)*b+x*2*c;
int g=a*x+b*y;
cout<<min(n,min(m,g));
system("pause");
return 0;
}