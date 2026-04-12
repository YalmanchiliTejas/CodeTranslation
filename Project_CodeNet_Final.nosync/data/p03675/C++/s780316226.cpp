#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int maxn = 2e5 + 10;
int n , ans[maxn] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	int j = n - 1 , k = 0;
	for(int i=n-1,ct=0;i>=0;i--,ct++)
	{
		if(ct % 2 == 0) ans[k++] = a[i];
		else ans[j--] = a[i];
	}
	for(int i=0;i<n;i++) cout << ans[i] << " ";
}