#include <bits/stdc++.h>
typedef int INT;
#define int long long
using namespace std;

const int MAX = 1e5 + 10;

INT main()
{
	int n; cin>>n;
	int a[MAX],c[MAX]={0};

	for(int i=1;i<=n;i++) cin>>a[i];

	for(int i=1;i<n;i++){
		if(i%2){
			c[i]--;
			c[i+1]++;
		}
		else{
			c[i]++;
			c[i+1]--;
		}
	}

	int ans1=0;
	sort(a+1,a+n+1);
	sort(c+1,c+n+1);
	for(int i=n;i>0;i--) ans1 += a[i]*c[i];
	for(int i=1;i<=n;i++) c[i]=0;
	for(int i=1;i<n;i++){
		if(i%2){
			c[i]++;
			c[i+1]--;
		}
		else{
			c[i]--;
			c[i+1]++;
		}
	}
	int ans2=0;
	sort(c+1,c+n+1);
	for(int i=n;i>0;i--) ans2 += a[i]*c[i];

	cout<<max(ans2,ans1)<<endl;	

}