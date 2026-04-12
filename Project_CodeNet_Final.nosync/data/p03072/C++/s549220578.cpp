#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll infll=9223372036854775806;
const int inf=2147483646;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,i,a[100],m,ans=1;
	cin>>n;
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	m=a[0];
	for (i=1;i<n;i++){
		if (a[i]>=m){
			ans++;
			m=a[i];
		}
	}
	cout<<ans;
	return 0;
}