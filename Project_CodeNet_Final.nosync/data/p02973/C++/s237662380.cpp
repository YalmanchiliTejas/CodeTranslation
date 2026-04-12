#include<bits/stdc++.h>
using namespace std;
int a[100007],f[100007],ans,n;
int main(){
	cin>>n;
	for(int i=n;i>=1;--i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)//逆向遍历
		if(f[ans]<=a[i])//如果f数组里比较小，把a数组放进f数组，让大的放在ans位置上
            f[++ans]=a[i];
		else
            f[upper_bound(f+1,f+1+ans,a[i])-f]=a[i];//f数组比较大，把它变成a数组的数，继续向前找更小的，使得这一串只要染色一次
	cout<<ans;//ans就是f数组里的数字个数，代表有一些小的数字在后面没有办法找到前面更小的数字使得一齐染色
	return 0;
}
