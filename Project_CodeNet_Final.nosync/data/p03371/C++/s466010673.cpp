#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
int a,b,ab,an,bn,ansa,ansb,ansc;
int main(){
cin>>a>>b>>ab>>an>>bn;
int bi=max(an,bn);
ansa=bi*2*ab;
ansb=an*a+bn*b;
if(bi==an)
ansc=bn*2*ab+(an-bn)*a;
else
ansc=an*2*ab+(bn-an)*b;
ansa=min(ansa,ansb);
ansa=min(ansa,ansc);
cout<<ansa;
system("pause");
return 0;
}