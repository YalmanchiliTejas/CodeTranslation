#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n-1;i>s;i--)
#define rep_re(i,s,n)for(ll i = n-1;i>=s;i--)
ll MOD = 1e9 + 7;

int main() {
	string s; cin >> s;

	if (s[0] == s[1] && s[1] == s[2]){
		cout << "No" << endl;
}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}
