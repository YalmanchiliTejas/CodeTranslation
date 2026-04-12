#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,a[100097],d[100099],t,l,r,ss,m;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	
	d[t=1]=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]<=d[t]){
			d[++t]=a[i];
			continue;
		}
		/*
		if(a[i] > d[1]){
			d[1]=a[i];
			continue;
		} */ //lower  //upper //set
		l=1; r=t;
		while(l<=r){
			m=l+r>>1;
			if(d[m]<a[i])ss=m,r=m-1;
			else l=m+1;
		}
		d[ss]=a[i];
	}
	
	cout<<t;
	 
}