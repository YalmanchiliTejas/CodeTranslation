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
	//	freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	b = a;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(b[i] <= a[n/2-1])cout << a[n/2] << '\n';
		else cout << a[n/2-1] << '\n';
	}
}