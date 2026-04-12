#include "bits/stdc++.h"
using namespace std;
int a[200005];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> v;
	if(n & 1){
	for(int i = 1; i <= n; i+=2)v.push_back(i);
	reverse(v.begin(),v.end());
	for(int i = 2; i <= n; i+=2)v.push_back(i);
	}	else {
	for(int i = 2; i <= n; i+=2)v.push_back(i);
	reverse(v.begin(),v.end());
	for(int i = 1; i <= n; i+=2)v.push_back(i);
	}
	for(int i = 0; i < n; i++)cout << a[v[i]] << ' ';
	return 0;
}