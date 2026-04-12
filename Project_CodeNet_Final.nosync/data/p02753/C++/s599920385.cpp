#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin>>s;
int n=s.size();
int cnt=0,cnt1=0,i;
for(i=0;i<n;i++)
{
 if(s[i]=='A')
 cnt++;
 if(s[i]=='B')
 cnt1++;
}
if(cnt1>=1&&cnt>=1)
cout<<"Yes"<<"\n";
else
cout<<"No"<<"\n";
}