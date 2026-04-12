#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, h[50], cnt=0;
	cin>>n;
	int mx=0;
	for(int i=0; i<n; i++)
	{
        cin>>h[i];
        mx=max(mx, h[i]);
        if(h[i]>=mx) cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}
