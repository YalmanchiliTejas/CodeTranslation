#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define  sci(x)   scanf("%d", &x)
#define  scl(x)   scanf("%lld", &x)
#define  scd(x)   scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//CODE TONOY
	int n;
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		if (i%15==0)
		sum+=600;
		
		else
		sum+=800;
	}
	cout<<sum;	
	return 0;
}