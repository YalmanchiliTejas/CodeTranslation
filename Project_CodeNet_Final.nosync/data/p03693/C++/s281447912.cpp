#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  c+=a*100+b*10;
  c%4?puts("NO"):puts("YES");
}
