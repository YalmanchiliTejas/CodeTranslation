#include<bits/stdc++.h>
using namespace std;
long long int ncr(long long int n,long long int r)
{
long long int i,s=1,t=1;
for(i=1;i<=r;i++)
{
s=s*(n+1-i);
t=t*i;
}
return s/t;
}
int main()
{
long long int k,l,m=0,n,p=0,i;
string s;
cin>>s;
cin>>k;
l=s.length();
if(k==1)
  n=9;
else if(k==2)
    n=81;
else
    n=729;
if(l<k)
{
cout<<"0"<<endl;
return 0;
}
if(l>k)
{
 m=m+ncr(l-1,k)*n;
}

for(i=0;i<l;i++)
{
if(s[i]>'0'){
p++;
if((l-1-i)>=k-p+1&&p!=1){
 m=m+ncr(l-1-i,k-p+1)*pow(9,k-p+1);
//cout<<"hello1"<<endl;
}
if((l-1-i)>=k-p&&k!=p){
m=m+ncr(l-1-i,k-p)*pow(9,k-p)*(s[i]-'1');
//cout<<"hello2"<<endl;
}
else{
   m=m+(s[i]-'0');
   //cout<<"hello3"<<endl;
}
//cout<<s[i]-'0'<<endl;
if(p==k)
    break;
}
}

cout<<m<<endl;


}
