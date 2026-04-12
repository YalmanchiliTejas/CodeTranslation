#include <bits/stdc++.h>

using namespace std;

int n;
int h[200001];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=n-1;i>=0;i-=2) cout<<h[i]<<' ';
	for (int i=n%2;i<n;i+=2) cout<<h[i]<<' ';
	cout<<endl;
}
