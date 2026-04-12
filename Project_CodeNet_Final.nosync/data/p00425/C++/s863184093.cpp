#include<iostream>
#include<string>
using namespace std;

int main(){
int n;
string s;
string f[6]={"North","East","West","South","Right","Left"};
int cf[6][3]={{1,5,2},{4,1,0},{2,1,5},{3,0,2},{0,2,3},{0,4,1}};
int sum=1;
int a=0;
int me[6]={1,2,3,5,4,6};
int ne[3];
while(cin>>n){
	sum=1;
	int me[6]={1,2,3,5,4,6};
	if(n==0)break;
	a=0;
for(int i=0;i<n;i++){
cin>>s;
for(int j=0;j<6;j++){
if(s==f[j]){
for(int k=0;k<3;k++){
ne[k]=me[cf[j][k]];}
for(int k=0;k<3;k++){
me[k]=ne[k];}
me[3]=7-me[1];
me[4]=7-me[2];
me[5]=7-me[0];
break;
}}
sum+=me[0];}
cout<<sum<<endl;}
}