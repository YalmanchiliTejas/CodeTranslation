#include<stdio.h>
int main () {
int n,i,j,k,a,b,x[30][60];
char s[60][60],e[5];
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%s",s[i]);
}
for(i=1;i<=26;i++){
for(j=1;j<=n;j++){
x[i][j]=0;
for(k=0;s[j][k]!='\0';k++){
if (s[j][k]=='a'+i-1) x[i][j]=x[i][j]+1;
}
}
}
for(i=1;i<=26;i++){
for(j=1;j<n;j++){
if (x[i][j]<x[i][j+1]) x[i][j+1]=x[i][j];
}
e[0]='a'+i-1;
for(k=1;k<=x[i][n];k++){
printf("%c",e[0]);
}
}
printf("\n");
return 0;
}