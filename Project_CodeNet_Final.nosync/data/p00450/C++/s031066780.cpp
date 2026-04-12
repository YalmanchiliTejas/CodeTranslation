#include<stdio.h>

int main(){

int n[100001];
int N;
while(1){
scanf("%d",&N);
if(N==0)break;
for(int i=0;i<N;i++)
scanf("%d",&n[i]);

for(int i=0;i<N;i++)
if(i%2==1){
for(int j=i-1;j>=0;j--)
if(n[j]!=n[i])n[j]=n[i];
else if(n[j]==n[i])break;
}
int c=0;
for(int i=0;i<N;i++)
if(n[i]==0)c++;

printf("%d\n",c);
}
return 0;
}