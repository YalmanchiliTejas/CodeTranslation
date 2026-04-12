#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
long a,b,c;
int n,i,sum,lon;


cin>>a>>b>>c;
a=a-c;
lon=c+b;
sum=a/lon;

cout<<sum;

return 0;
}