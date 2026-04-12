#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(void) {

	int n,h[20]={},maxn=0,num=0;

	cin>>n;

	for (int i = 0; i < n; i++) {
		cin>>h[i];
		if(h[i]>=maxn)num++;

		maxn=max(maxn,h[i]);
	}
	cout<<num<<"\n";

	return 0;
}
