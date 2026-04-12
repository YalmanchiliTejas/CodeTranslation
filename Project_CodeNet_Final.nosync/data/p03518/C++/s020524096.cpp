#include<bits/stdc++.h>
using namespace std;
int n,a[101000],c[101000],tp;
bool chk(){
	for(int i=2;i<=n;++i)if(a[i]<a[i-1])return false;
	return true;
}
void rot(){
	c[++tp]=1;
	int x=a[1];
	for(int i=1;i<n;++i)a[i]=a[i+1];
	a[n]=x;
}
void sp(){
	c[++tp]=n-1;
	swap(a[1],a[n]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),a[i]++;
	for(int i=1;i<=n;++i){
		while(a[n]!=i)rot();
		while(a[n-1]!=i-1&&i>1)sp(),rot();
	}
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)printf("%d\n",c[i]);
}