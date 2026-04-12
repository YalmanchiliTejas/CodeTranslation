#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int maxn = 2e5+10;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int a[maxn],f[maxn],len=0;
int main(){
	int n=read();
	for(register int i=1;i<=n;i++)a[i]=read();
	f[++len]=a[1];
	for(register int i=2;i<=n;i++){
		if(a[i]>f[1])f[1]=a[i];
		else{
			if(a[i]<=f[len])f[++len]=a[i];
			else {
				int l=1,r=len,ans;
				while(l<=r){
					int mid=(l+r)>>1;
					if(f[mid]>=a[i])l=mid+1;
					else r=mid-1;
				}	
				f[l]=a[i];
			}
		}
	}
	printf("%d\n",len);
	return 0;
}