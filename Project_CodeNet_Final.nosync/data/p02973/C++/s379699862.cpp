#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	int n;
	cin >> n;
	multiset<int> sett;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		auto it = sett.lower_bound(a);
		if(it == sett.begin())
			sett.insert(a);
		else{
			it--;
			sett.erase(it);
			sett.insert(a);
		}
	}
	cout << sett.size();
	return 0;
}
