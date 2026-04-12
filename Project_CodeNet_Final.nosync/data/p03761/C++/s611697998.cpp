#include<bits/stdc++.h>
using namespace std;
int n,b[133],a[133];
string s;
int main(){
cin>>n;
memset(b,127,sizeof(b));
for(int i=1;i<=n;i++){
cin>>s;
memset(a,0,sizeof(a));
for(int j=0;j<s.size();j++)
a[s[j]]++;
for(int j=97;j<=122;j++)
b[j]=min(a[j],b[j]);}
for(int i=97;i<=122;i++)
for(int j=1;j<=b[i];j++)
cout<<char(i);}