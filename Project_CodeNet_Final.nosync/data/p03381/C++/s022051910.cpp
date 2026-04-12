#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N=200005;
int n;
int a[MAX_N],b[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n){
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n);
		int h1=b[n/2-1],h2=b[n/2],ans;
		for(int i=0;i<n;++i)
		{
			if(a[i]<=h1){
				ans=h2;
			}else	ans=h1;
			cout<<ans<<endl;
		}
	}
	
	return 0;
}