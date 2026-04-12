#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
const int N=505;
ll n,s[N],t[N],u[N],v[N],a[N][N];
bool work(){
	for(int i=0;i<64;i++){
		for(int j=1;j<=n;j++)
			if(s[j]==0 and (u[j]&(1ull<<i)))
				for(int k=1;k<=n;k++)
					a[j][k]|=(1ull<<i);
		for(int j=1;j<=n;j++)
			if(t[j]==0 and (v[j]&(1ull<<i)))
				for(int k=1;k<=n;k++)
					a[k][j]|=(1ull<<i);
		for(int j=1;j<=n;j++){
			if(!(s[j]==1 and (u[j]&(1ull<<i))))
				continue;
			int w=0;
			for(int k=1;k<=n;k++)
				if((a[j][k]&(1ull<<i)) or (v[k]&(1ull<<i))){
					w=k;
					break;
				}
			if(w){
				a[j][w]|=(1ull<<i);
				continue;
			}
			for(int k=1;k<=n;k++){
				if(t[k]==1)continue;
				int num=0;
				for(int l=1;l<=n;l++)
					if(a[l][k]&(1ull<<i))
						num++;
				if(num<n-1){
					w=k;
					break;
				}
			}
			if(!w)return false;
			a[j][w]|=(1ull<<i);
		}
		for(int j=1;j<=n;j++){
			if(t[j]==1 and (v[j]&(1ull<<i))){
				int w=0;
				for(int k=1;k<=n;k++)
					if((a[k][j]&(1ull<<i)) or (u[k]&(1ull<<i))){
						w=k;
						break;
					}
				if(w){
					a[w][j]|=(1ull<<i);
					continue;
				}
				for(int k=1;k<=n;k++){
					if(s[k]==1)continue;
					int num=0;
					for(int l=1;l<=n;l++)
						if(a[k][l]&(1ull<<i))
							num++;
					if(num<n-1){
						w=k;
						break;
					}
				}
				if(!w)return false;
				a[w][j]|=(1ull<<i);
			}
		}
		for(int j=1;j<=n;j++){
			ll w=(1ull<<i);
			if(s[j]==0)
				for(int k=1;k<=n;k++)
					w&=a[j][k];
			else{
				w=0;
				for(int k=1;k<=n;k++)
					w|=a[j][k]&(1ull<<i);
			}
			if(w!=(u[j]&(1ull<<i)))
				return false;
		}
		for(int j=1;j<=n;j++){
			ll w=(1ull<<i);
			if(t[j]==0)
				for(int k=1;k<=n;k++)
					w&=a[k][j];
			else{
				w=0;
				for(int k=1;k<=n;k++)
					w|=a[k][j]&(1ull<<i);
			}
			if(w!=(v[j]&(1ull<<i)))return 0;
		}
	}
	return true;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		s[i]=read();
	for(int i=1;i<=n;i++)
		t[i]=read();
	for(int i=1;i<=n;i++)
		scanf("%llu",u+i);
	for(int i=1;i<=n;i++)
		scanf("%llu",v+i);
	if(!work())return puts("-1"),0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%llu%c",a[i][j],j==n?'\n':' ');	
	return 0;
}