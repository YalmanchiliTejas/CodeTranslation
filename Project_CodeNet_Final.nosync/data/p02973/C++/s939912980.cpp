#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define re register
#define ll long long
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=500010;
int n,a[N],len,f[N],o[N];
int main(){
	n=gi();for(int i=1;i<=n;i++)a[i]=gi();
	for(int i=n;i;i--){
		if(f[len]<=a[i])f[++len]=a[i];
		else{
			int k=upper_bound(f+1,f+len+1,a[i])-f;
			f[k]=a[i];
		}
	}
	printf("%d\n",len);
	return 0; 
}
