#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<ctype.h>
#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<numeric>
#include<string>
using namespace std;
typedef long long ll;

ll ds(ll digit) {
	ll res = 0;
	while (digit!=0) {
		res += digit % 10;
		digit /= 10;
	}
	return res;
}
ll MOD = 1000000007;
int main() {
	string S;
	cin>>S;
	ll cnt = 0;
	for (ll i = 0; i+1<S.size();++i) {
		if (S[i]=='A'&&S[i+1]=='C')
        {++cnt;}
	}
	if (cnt > 0)
		cout << "Yes" << endl;
	else
	cout << "No" << endl;}

