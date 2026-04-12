#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define inf 1e18+9
using namespace std;
int32_t main(){
	if(fopen("input.txt", "r"))
	freopen("input.txt", "r", stdin),
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	string st;
	cin >> st;
	if(st=="AAA" or st=="BBB")
		cout << "No";
	else
		cout << "Yes";
}