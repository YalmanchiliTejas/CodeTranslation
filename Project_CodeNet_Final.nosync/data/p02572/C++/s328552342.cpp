#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9+7;

int main() {
	int t = 1; 
	//cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector <ll> a(n);
		ll sum = 0, answer = 0;
		for (int i = 0; i < n; i++) {
			cin>>a[i];
			answer += a[i]*sum;
			answer %= mod;
			sum += a[i];
			sum %= mod;
		}
		cout<<answer;
	}
}
//9.2 x 10^18