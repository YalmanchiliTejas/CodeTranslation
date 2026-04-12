#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;

int main() {
	ll n, sum = 0LL, curr;
	cin>>n;

	ll result = 0LL;
	for(int i=0;i<n;i++) {
		cin>>curr;
		result += (curr * sum) % mod;
		if(result > mod) result -= mod;

		sum += 1LL * curr;
		if(sum > mod) sum -= mod;
	}
	cout<<result<<"\n";
}