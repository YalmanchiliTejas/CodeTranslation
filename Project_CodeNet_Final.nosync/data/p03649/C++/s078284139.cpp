#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
typedef long long ll;

int n;
ll a[51], k; 

int main()
{
	cin >> n;
	fo(i,0,n-1) cin >> a[i];
	while(1)
	{
		ll t, s; t = s = 0;
		fo(i,0,n-1) {t=a[i]/n;a[i]%=n;a[i]-=t;s+=t;}
		if(!s)break;
		fo(i,0,n-1) a[i]+=s;
		k += s;
	}
	cout << k << endl;
	return 0;
}