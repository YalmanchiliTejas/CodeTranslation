#include<bits/stdc++.h>
using namespace std;
int main()
{
string t;
cin>>t;
if((t[0]=='B'&&t[1]=='A')||(t[0]=='A'&&t[1]=='B')||(t[1]=='B'&&t[2]=='A')||(t[1]=='A'&&t[2]=='B'))
cout<<"Yes";
else
cout<<"No";
}