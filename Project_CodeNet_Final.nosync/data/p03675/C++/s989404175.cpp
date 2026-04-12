#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;cin>>n;
	int A[n];
	for(int i = 0;i < n;i++) cin>>A[i];
	
	for(int j = n-1;j >= 0;j-=2) cout<<A[j]<<" ";
	int s = 0;
	if(n%2 != 0) s = 1;
	while(s < n) {
		cout<<A[s]<<" ";
		s += 2;
	}

	return 0;
}