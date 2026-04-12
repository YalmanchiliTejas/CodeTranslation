#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 2e5+5, mod = 1e9+7;
int val[N];
int main() 
{
	int n, cnt = 0;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	vector<int> vec(N, -1);
	for(int i=0; i<n; i++)
	{
		int l = lower_bound(vec.begin(), vec.end(), a[i])-vec.begin()-1;
		if(vec[l] == -1) cnt++;
		vec[l] = a[i];
	}
	cout << cnt << endl;
}