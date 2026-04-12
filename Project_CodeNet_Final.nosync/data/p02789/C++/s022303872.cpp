#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
//#include <bits/stdc++.h>
#define ll  long long
#define cn(i,n,a) for(int i=0;i<n;i++)cin>>a[i];
#define co(i,n,a) for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
const ll mod = 1e9 + 7;
using namespace std;
void right() {
	cout << "Yes\n";
	exit(0);
}
void fail() {
	cout << -1;
	exit(0);
}
ll gcd(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}
map<int, int>m;
int main()
{
	int n, k;
	cin >> n >> k;
	if (n == k)cout << "Yes";
	else cout << "No";
}