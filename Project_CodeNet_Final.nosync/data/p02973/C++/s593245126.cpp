#include<bits/stdc++.h>
using namespace std;
int a[100005];
int d[100005];
int main()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	int len=0;
	d[len]=1e9+5;
	for (int i=1;i<=n;i++){
		if (a[i]<=d[len]){
			d[++len]=a[i];
			continue;
		}
		int head=1, tail=len;
		while (head<tail){
			int mid=(head+tail)/2;
			if (a[i]<=d[mid]) head=mid+1;
			else tail=mid;
		}
		d[head]=a[i];
	}
	cout << len;
	return 0;
}