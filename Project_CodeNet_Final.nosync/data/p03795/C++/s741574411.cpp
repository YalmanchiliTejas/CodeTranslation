#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
long long n;
int main()
{
 scanf("%I64d",&n);
 long long x=800*n;
 long long y=n/15*200;
 cout<<x-y;
 return 0;
}
