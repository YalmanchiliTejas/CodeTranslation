#include <bits/stdc++.h>
using namespace std;
const int E=100000;
int a[E],col[E];
int main(){
	int n;
	while(true){
	cin>>n;
	if(n==0)	return 0;
	int now=0;
	for(int i=0;i<E;i++){
		col[i]=-1;	a[i]=0;
	}
	for(int i=1;i<=n;i++){
		int p;	cin>>p;
		if(i==1)	col[now]=p;
		if(i%2==0){
			if(col[now]==p)	a[now]++;
			else{
				if(now==0){
					a[now]++;
					col[now]=p;
				}
				else{
					a[now-1]+=a[now]+1;
					a[now]=0;	col[now]=-1;
					now--;
				}
			}
		}
		else{
			if(col[now]==p)	a[now]++;
			else{
				now++;
				a[now]=1;
				col[now]=p;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(col[i]==0)	ans+=a[i];
	}
	cout<<ans<<endl;
	}
	return 0;
}
		