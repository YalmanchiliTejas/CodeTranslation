#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int a[maxn+5];
int b[maxn+5];
inline int Read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
	int n;
	n=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	
		for(int i=1;i<=n;i++){
			if(a[i]<=b[n/2]){
				printf("%d\n",b[n/2+1]); 
			}else{
				printf("%d\n",b[n/2]);
			}
		}
	
	return 0;
} 