#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define FOR(S,X) for(int i=S;i<X;i++)
#define FOR2(S,X) for(int j=S;j<X;j++)
const long long int MOD = 1000000007;
int main() {
	unsigned long long int sum=0,n,a;
	vector<unsigned long long int> s, aa;
	cin >> n;
	cin >> a;
	aa.push_back(a);
	s.push_back(a);
	FOR(1,n) {
		cin >> a;
		aa.push_back(a);
		s.push_back((a+s[i-1])%MOD);
	}
	FOR(1, n) {
		sum += (s[i - 1] * aa[i])%MOD;
	}
	cout << sum%MOD<<endl;
	return 0;
}