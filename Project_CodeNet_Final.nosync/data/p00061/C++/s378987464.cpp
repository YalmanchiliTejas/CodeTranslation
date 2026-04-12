#include<iostream>
using namespace std;
int main(){
long n,j=1,k,a[101],b[31]={0},d[31];
char c;
while(cin>>n){
cin>>c>>a[j];
if(n==0)break;
b[a[j]]++;j++;
}
n=j;
for(k=1,j=30;j>=0;j--)if(b[j]!=0)d[j]=k++;
while(cin>>j){
cout<<d[a[j]]<<endl;
}
return 0;
}