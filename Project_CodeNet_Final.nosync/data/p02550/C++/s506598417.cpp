#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, x, m;
	cin >> n >> x >> m;
	unordered_map<int, int> mp, sum;
	int a = 0, b = 0, c = 0;
	int i = 0;
	while(mp.count(x) == 0){
		mp[x] = i;
		b += x;
		sum[i] = b;
		i++;
		x = (x * x) % m;
	}
	a = sum[mp[x]-1];
	b -= a;
	int numCycle = (n - mp[x]) / (i - mp[x]);
	b *= numCycle;
	int rem = (n - mp[x]) % (i - mp[x]);
	c = sum[mp[x] + rem - 1] - sum[mp[x] - 1];
	cout << a + b + c;
    return 0;
}