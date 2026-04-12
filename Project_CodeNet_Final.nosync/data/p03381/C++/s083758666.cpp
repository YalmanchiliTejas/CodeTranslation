#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cerr << fixed << #x << " is " << x << endl;
#define ii pair<int, int>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> v_sorted(n);

	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		v_sorted[i] = v[i];
	}
	int get = (n+1)/2;
	sort(v_sorted.begin(), v_sorted.end());
	for(int i = 0; i < n; i++)
	{
		int find = lower_bound(v_sorted.begin(), v_sorted.end(), v[i])-v_sorted.begin();
		if(find < get)
			cout << v_sorted[get] << endl;
		else
			cout << v_sorted[get-1] << endl;
	}

	return 0;
}
