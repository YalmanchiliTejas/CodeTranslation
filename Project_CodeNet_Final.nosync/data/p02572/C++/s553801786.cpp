#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
long long int sum[200005];
int main(void)
{
	int n;
  	cin >> n;
  	for(int i=0;i<n;i++)
    {
    	cin >> a[i];
    }
  	sum[n-1] = 0;
  	long long int m = 1e9 + 7;
  	for(int i=1;i<n;i++)
    {
    	sum[n-1-i] = (sum[n-i] + a[n-i])%m;
    }
  	long long int ans = 0;
    for(int i = 0;i<n;i++)
    {
    	ans= ((ans)%m+(a[i]*sum[i])%m)%m;
    }
  	cout << ans << endl;
}
