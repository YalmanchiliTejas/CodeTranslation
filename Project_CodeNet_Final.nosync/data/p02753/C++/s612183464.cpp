/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
string s;
cin>>s;
string ans="No";
for(int i=0;i<3;i++)
{
if(s[i]!=s[0])
{
ans="Yes";
}
}
cout<<ans;
}

