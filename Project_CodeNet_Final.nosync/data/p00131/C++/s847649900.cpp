#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int f(int p[][12],int q[][12],int x){
  int i,j;
  int r[12][12],s[12][12];
  if(x==11){
    for(i=2;i<10;i++){
      for(j=1;j<11;j++){
	if(p[j][i]){
	  p[j  ][i  ]=(p[j  ][i  ]+1)%2;
	  p[j-1][i+1]=(p[j-1][i+1]+1)%2;
	  p[j  ][i+1]=(p[j  ][i+1]+1)%2;
	  p[j+1][i+1]=(p[j+1][i+1]+1)%2;
	  p[j  ][i+2]=(p[j  ][i+2]+1)%2;
	  q[j][i+1]=1;
	}
      }
    }
    for(i=1;i<11;i++){
      if(p[i][10])
	break;
    }
    if(i==11){
      for(i=1;i<11;i++){
	for(j=1;j<10;j++)
	  cout<<q[j][i]<<" ";
	cout<<q[j][i]<<endl;
      }
      return 1;
    }
  }else if(x==10){
    if(p[x][1]){
      memcpy(r,p,sizeof(r));
      memcpy(s,q,sizeof(s));
      r[x  ][1]=(r[x  ][1]+1)%2;
      r[x-1][2]=(r[x-1][2]+1)%2;
      r[x  ][2]=(r[x  ][2]+1)%2;
      r[x+1][2]=(r[x+1][2]+1)%2;
      r[x  ][3]=(r[x  ][3]+1)%2;
      s[x  ][2]=1;
      if(f(r,s,x+1))
	return 1;
    }else{
      memcpy(r,p,sizeof(r));
      memcpy(s,q,sizeof(s));
      if(f(r,s,x+1))
	return 1;
    }
  }else{
      if(p[x][1]){
      memcpy(r,p,sizeof(r));
      memcpy(s,q,sizeof(s));
      r[x+1][0]=(r[x+1][0]+1)%2;
      r[x  ][1]=(r[x  ][1]+1)%2;
      r[x+1][1]=(r[x+1][1]+1)%2;
      r[x+2][1]=(r[x+2][1]+1)%2;
      r[x+1][2]=(r[x+1][2]+1)%2;
      s[x+1][1]=1;
      if(f(r,s,x+1))
	return 1;
      memcpy(r,p,sizeof(r));
      memcpy(s,q,sizeof(s));
      r[x  ][1]=(r[x  ][1]+1)%2;
      r[x-1][2]=(r[x-1][2]+1)%2;
      r[x  ][2]=(r[x  ][2]+1)%2;
      r[x+1][2]=(r[x+1][2]+1)%2;
      r[x  ][3]=(r[x  ][3]+1)%2;
      s[x  ][2]=1;
      if(f(r,s,x+1))
	return 1;
    }else{
      memcpy(r,p,sizeof(r));
      memcpy(s,q,sizeof(s));
      if(f(r,s,x+1))
	return 1;
      memcpy(r,p,sizeof(r));
      memcpy(s,q,sizeof(s));
      r[x+1][0]=(r[x+1][0]+1)%2;
      r[x  ][1]=(r[x  ][1]+1)%2;
      r[x+1][1]=(r[x+1][1]+1)%2;
      r[x+2][1]=(r[x+2][1]+1)%2;
      r[x+1][2]=(r[x+1][2]+1)%2;
      s[x+1][1]=1;
      r[x  ][1]=(r[x  ][1]+1)%2;
      r[x-1][2]=(r[x-1][2]+1)%2;
      r[x  ][2]=(r[x  ][2]+1)%2;
      r[x+1][2]=(r[x+1][2]+1)%2;
      r[x  ][3]=(r[x  ][3]+1)%2;
      s[x  ][2]=1;
      if(f(r,s,x+1))
	return 1;
    }
  }
  return 0;
}
int main(){
  int i,j,k;
  int q[12][12],r[12][12],n;
  int (*p)[12][12];
  cin>>n;
  p=new int[n][12][12];
  for(i=0;i<n;i++)
    for(j=1;j<11;j++)
      for(k=1;k<11;k++)
	cin>>p[i][k][j];
  for(i=0;i<n;i++){
    memcpy(r,&p[i][0][0],sizeof(r));
    memset(q,0,sizeof(q));
    f(r,q,1);
    memcpy(r,&p[i][0][0],sizeof(r));
    memset(q,0,sizeof(q));
    r[1][0]=(r[1][0]+1)%2;
    r[0][1]=(r[0][1]+1)%2;
    r[1][1]=(r[1][1]+1)%2;
    r[2][1]=(r[2][1]+1)%2;
    r[1][2]=(r[1][2]+1)%2;
    q[1][1]=1;
    f(r,q,1);
  }
  delete [] p;
  return 0;
}