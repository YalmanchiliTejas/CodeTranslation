#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll MAXN= 2e5+5;
const ll MOD= 1e9+7; 
ll a[MAXN];
ll s[MAXN];
int main()
{
	int n;
	ll sum=0;
	cin >> n;
	ll t=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		s[i]=a[i]+t;
		t=s[i];
	}
	for(int i=0;i<n-1;i++){
		sum=((s[i]%MOD*a[i+1]%MOD)%MOD+sum)%MOD;
	}
	cout << sum << endl;
	return 0;
}