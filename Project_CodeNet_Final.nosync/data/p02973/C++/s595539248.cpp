#include<bits/stdc++.h>
using namespace std;
int n,a[200010],ans[200010],la;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for(int i=1;i<=n;i++){
		if(ans[la]<=a[i]) ans[++la]=a[i];
		else{
			int p=upper_bound(ans+1,ans+la+1,a[i])-ans;
			ans[p]=a[i];
		}
	}
	cout<<la<<endl;
	return 0;
}