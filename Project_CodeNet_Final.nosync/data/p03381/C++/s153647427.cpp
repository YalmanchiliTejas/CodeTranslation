#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

pair<int , int> a[maxn];

int res[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i].first , a[i].second = i;

	sort(a , a + n);

	for(int i = 0; i < n / 2; i++)
		res[a[i].second] = a[n / 2].first;

	for(int i = n / 2; i < n; i++)
		res[a[i].second] = a[n / 2 - 1].first;

	for(int i = 0; i < n; i++)
		cout << res[i] << endl;
}





