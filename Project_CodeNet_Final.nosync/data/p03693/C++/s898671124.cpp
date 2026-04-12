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
int main(){
int a,b,c;
cin>>a>>b>>c;
int d=a*100+b*10+c;
if(d%4==0)
cout<<"YES";
else
cout<<"NO";
system("pause");
return 0;
}