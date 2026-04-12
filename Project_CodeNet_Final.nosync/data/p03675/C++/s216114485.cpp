#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int i=n-1;
	for(;i>=0;i-=2)cout << a[i] << ' ';
	i+=2;
	if(!i)i++;
	else i--;
	for(;i<n;i+=2)cout << a[i] << ' ';
	cout << '\n';
}