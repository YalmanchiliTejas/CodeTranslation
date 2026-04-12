#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll MOD=1e9+7;
ll MAX=1e17;

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int b[n+1],a[n+1];
	for (int i = 0; i < n; ++i)
		{
			cin>>a[i+1];
		}	
	if(n%2==0){
		int j=0;
		for(int i=n;i>1;i-=2,j++){
			b[j]=a[i];
		}
		for (int i = 1; i < n; i+=2,++j)
		{
			b[j]=a[i];
		}
	}
	else{
		int j=0;
		for(int i=n;i>=1;i-=2,j++){
			b[j]=a[i];
		}
		for (int i = 2; i < n; i+=2,++j)
		{
			b[j]=a[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}