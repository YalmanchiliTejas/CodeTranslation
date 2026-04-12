#include <bits/stdc++.h>
using namespace std;

int n, a[200004];

int main() {
	cin>>n;
	for(int i = 1;i<=n;i++)	cin>>a[i];
	for(int i = n;i>0;i-=2)	cout<<a[i]<<" ";
	int start;
	if (n%2 == 0) start = 1;
	else	start = 2;
	for(int i = start;i<=n;i+=2)	cout<<a[i]<<" ";
	return 0;
}