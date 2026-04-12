#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
int n;
while(cin>>n,n){
int masu[20][20]={0};
int x=(n+3)/2,y=(n+1)/2;
int num=1;
masu[x][y]=num;
while(num!=n*n){
if(x+1>n&&y+1>n){
  for(int i=1;;i++){
	if(masu[i][y]==0){num++;masu[i][y]=num;x=i;break;}
  }
}
else if(x+1>n){y++;num++;masu[1][y]=num;x=1;}
else if(y+1>n){x++;num++;masu[x][1]=num;y=1;}
else if(masu[x+1][y+1]==0){x++;y++;num++;masu[x][y]=num;}
else if(x+2>n){num++;masu[1][y]=num;x=1;}
else {x+=2;num++;masu[x][y]=num;}
//cout<<num<<endl;
}
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
printf("%4d",masu[i][j]);
}
cout<<endl;
}
}
}