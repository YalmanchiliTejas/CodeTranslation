#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

const int maxn = 200000+22;

int a[maxn];
int b[maxn];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	int ans1=a[n/2];
	int ans2=a[n/2+1];
	for(int i=1;i<=n;i++){
		if(b[i]<=ans1){
			printf("%d\n",ans2);
		}else{
			printf("%d\n",ans1);
		}
	}

	return 0;
}
