#include<iostream>
using namespace std;

int main()
{	int a,b,c,d;
  cin>>a>>b>>c;
 d=a*100+b*10+c;
 if(d%4==0)
   cout<<"YES";
 else
   cout<<"NO";
 return 0;
}