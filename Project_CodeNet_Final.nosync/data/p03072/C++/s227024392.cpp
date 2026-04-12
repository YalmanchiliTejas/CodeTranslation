#include<bits/stdc++.h>
using namespace std;

int n,a[25],ans;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
    {
		int tag = 1;
		for(int j = 1; j < i; j++)
			if(a[j]>a[i]) tag = 0;
		if(tag) ans++;
	}
	cout << ans << endl;
	return 0;
}
