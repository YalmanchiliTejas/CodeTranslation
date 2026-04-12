#include <bits/stdc++.h>
#define MAXN 1000010
#define inf 0x3f3f3f3f
#define LL long long
#define pi acos(-1)
#define MOD 1000000007
using namespace std;



int main()
{
	int n,x,ans=0,tmp=0;
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		cin>>x;
		if (x>=tmp) ans++,tmp=x;
	}
	cout << ans << endl;
	return 0;
}