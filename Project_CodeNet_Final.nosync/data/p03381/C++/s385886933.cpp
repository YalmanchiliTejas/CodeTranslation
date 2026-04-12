#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxn=2e5+10;
int n,a[maxn],b[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		if(a[i]<=b[n/2])
			cout<<b[n/2+1]<<endl;
		else
			cout<<b[n/2]<<endl;
	return 0;
}