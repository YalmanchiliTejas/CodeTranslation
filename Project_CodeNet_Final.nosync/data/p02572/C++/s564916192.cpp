#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<long>a(n);
     unsigned long long s=0,p=0;for(int i=0;i<n;i++){cin>>a.at(i);s+=a.at(i);}
     for(int i=0;i<n-1;i++)
     {s-=a.at(i);p+=(s%1000000007)*a.at(i);p%=1000000007;}
cout<<p<<endl;}