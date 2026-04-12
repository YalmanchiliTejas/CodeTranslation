#include<bits/stdc++.h>
using namespace std;

int cmp(int x,int y){
	return x>y;
}

int main(){
	long long sum=0;
	int n,a[100010]={0},len,rin;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	len=1;rin=n;
	sum+=a[len]-a[rin];
	while(1){
		if(rin-len>2) sum+=a[len]+a[len+1]-a[rin]-a[rin-1],len++,rin--;
		else{
			if(rin-len==2) sum+=max(a[len]-a[len+1],a[len+1]-a[rin]);
			break;
		}
	}
	cout<<sum;
	return 0;
}