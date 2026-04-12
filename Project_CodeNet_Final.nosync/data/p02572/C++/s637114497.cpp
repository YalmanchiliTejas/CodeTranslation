#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;

int main()
{
	const ll modP = 1000000007;
	int n;
	cin>>n;
	vector<int> a(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}
	ll ans = 0;
	for(int i = 0; i < n-1; i++){
		sum = sum - a[i];
		ans += ((a[i]%modP) * (sum % modP)) % modP;
		ans = ans % modP;
	}
	cout<<ans<<endl;
	return 0;
}

