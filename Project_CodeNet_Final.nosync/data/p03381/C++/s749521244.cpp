#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n; cin >> n;
	long long int x[200005], a[200005];
	for(long long int i=0;i<n;i++){
		cin >> x[i];
		a[i] = x[i];
	}
	sort(a,a+n);
	long long int s = a[n/2-1];
	long long int t = a[n/2];
	for(long long int i=0;i<n;i++){
		if(s<x[i]){
			cout << s << endl;
		}else{
			cout << t << endl;
		}
	}
	return 0;
}