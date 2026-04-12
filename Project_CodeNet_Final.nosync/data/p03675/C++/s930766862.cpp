#include <bits/stdc++.h>
using namespace std;

const int p=1e5+5;
const int M=2*p;

int A[M],B[M];

int main() {
	int n;
	cin>>n;
	for (int i=1;i<=n;++i) scanf("%d",&A[i]);
	int l,r;
	l=r=p;
	B[p]=A[1];
	l--,r++;
	for (int i=2;i<=n;++i) {
		if (i&1) B[l--]=A[i];
		else B[r++]=A[i];
	}
	if (n&1) {
		for (int i=l+1;i<r;++i) cout<<B[i]<<" ";
	}
	else {
		for (int i=r-1;i>l;--i) cout<<B[i]<<" ";
	}
}