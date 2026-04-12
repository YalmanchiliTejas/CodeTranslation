#include<iostream>
#include<cstdio>
using namespace std;
int main(){
long i,j,k,n,m[225];
while(cin>>n,n){
for(i=0;i<n;i++)
for(j=0;j<n;j++)m[i*n+j]=0;
j=(n-1)/2;i=j+1;
for(k=1;k<=n*n;k++){
m[i*n+j]=k;
i++;j++;
L1:
if(i==n&&j==n){i=0;}
else if(j==n){j=0;}
else if(i==n){i=0;}
if(m[i*n+j]>0){i++;j--;goto L1;}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++)printf("%4d",m[i*n+j]);
printf("\n");
}
}
return 0;
}