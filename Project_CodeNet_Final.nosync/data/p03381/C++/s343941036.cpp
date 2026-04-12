#include <bits/stdc++.h>
using namespace std;
int main() {
long long n;
cin>>n;
long long a[n]={};
long long b[n+1]={};
long long r;
long long ca=0;
long long cb=0;
for(long long i=0; i<n;i++){
cin>>a[i];
b[i]=a[i];}
sort(a,a+n);
ca=a[n/2-1];
cb=a[n/2];
if(ca==cb){
for(long long i=0; i<n;i++){
cout<<ca<<endl;}}
else {
for(long long i=0; i<n;i++){
if(b[i]<=ca){
cout<<cb<<endl;}
else
cout<<ca<<endl;}}}

