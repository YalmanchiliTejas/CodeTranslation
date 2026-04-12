#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;

const ll INF = ll(1e18) + 1;

//--------------------------------------------------

ulli gcd(ulli a, ulli b) {
	return (b <= 0) ? a : gcd(b, a % b);
}

ulli lcm(ulli a, ulli b) {
	return a * b / gcd(a, b);
}

//---------------------------------------------------

void Main()
{
	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Main();
	
	return 0;
}