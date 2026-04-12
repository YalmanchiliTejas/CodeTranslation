#pragma GCC optmize ("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define spIO ios::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
typedef long double ld;
int n;
inline void solve()
{

}
int main()
{
	spIO;
	string s;
	cin >> s;
	if (s[0] != s[1] || s[1] != s[2])
		cout << "Yes";
	else
		cout << "No";
}