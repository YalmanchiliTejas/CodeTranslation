#include<iostream>
using namespace std;
string a;
int main()
{
cin>>a;
for(int i=1;i<a.size();i++)
{
if(a[i-1]=='A'&&a[i]=='C'){cout<<"Yes";return 0;}
}
cout<<"No";return 0;
}