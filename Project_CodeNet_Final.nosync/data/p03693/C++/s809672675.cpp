#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
int answer=a*100+b*10+c;
if(answer%4==0)
cout<<"YES";
else
cout<<"NO";
}