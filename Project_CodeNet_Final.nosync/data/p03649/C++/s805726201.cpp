#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=60;
ll n,a[N],base,ans,temp;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	base=n-1;
	bool flag=1;
	while(flag){
		flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]>base){
				flag=1,temp=(a[i]-base-1)/n+1;
				a[i]-=temp*n+temp;
				base-=temp,ans+=temp;
			}
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}