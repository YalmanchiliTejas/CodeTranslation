#include<iostream>
#include<string>
using namespace std;
int main (){
int n,m;
cin>>n>>m;
string str[10];
for(int i=0;i<n;i++){
 cin>>str[i];
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(str[i][j]=='#'){
for(int k=i+1;k<n;k++){
for(int l=0;l<j;l++){
if(str[k][l]=='#'){
 cout<<"Impossible"<<endl;
return 0;
}
}
}
for(int k=0;k<i;k++){
for(int l=j+1;l<m;l++){
if(str[k][l]=='#'){
 cout<<"Impossible"<<endl;
return 0;
}}}}}}
cout<<"Possible"<<endl;
return 0;
}
