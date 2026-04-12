#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int a[MAXN],b[MAXN];
int main()
{
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		int mid=n/2;
		for(int i=1;i<=n;i++){
			if(a[i]<=b[mid]) cout<<b[mid+1]<<endl;
			else cout<<b[mid]<<endl;
		}
	}
}