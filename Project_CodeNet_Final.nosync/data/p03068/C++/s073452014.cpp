#include<iostream>
using namespace std;

int main(){
/*int a,b,c;
cin>>a>>b>>c;
if(c>=a&&c<=b){
cout<<"Yes";}
else if(c>=b&&c<=a){
cout<<"Yes";}
else{
cout<<"No";}*/

int n,k;
cin>>n;
string s;
cin>>s>>k;
for(int i=0;i<s.length();i++){
if(s[i]!=s[k-1]){
s[i]='*';}}
cout<<s;
return 0;}
