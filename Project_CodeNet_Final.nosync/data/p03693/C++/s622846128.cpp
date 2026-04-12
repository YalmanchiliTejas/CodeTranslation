#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
using namespace std;
signed main(){
	int a,b,c;
	cin >> a >> b >> c;
	a *= 100;
	b *= 10;
	int ans = a + b + c;
	(ans%4 == 0)? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}