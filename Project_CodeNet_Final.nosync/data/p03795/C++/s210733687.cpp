#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,s,td;
int main()
{
cin>>n;
td=n;
while(td>=15)td-=15,s++;
cout<<n*800-s*200<<endl;
return 0;
}