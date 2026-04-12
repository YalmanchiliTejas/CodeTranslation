#include<iostream>
#include <iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<string.h>
#include<math.h>
#include<unordered_map>
#include <deque>
using namespace std;


typedef long long ll;


int main()
{
	int n;
	vector<ll> ar,ori;

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		ar.push_back(a);
		ori.push_back(a);
	}
	sort(ar.begin(), ar.end());
	ll p = ar[(n - 1) / 2];

	for (int i = 0; i < n; i++) {
		if (ori[i] > p) {
			cout << ar[(n-1)/2] << endl;
		}
		else
		{
			cout << ar[(n - 1) / 2 +1] << endl;
		}
	}


	return 0;
}