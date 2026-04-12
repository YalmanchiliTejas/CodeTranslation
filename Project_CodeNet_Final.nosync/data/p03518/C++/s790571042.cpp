#include<bits/stdc++.h>
using namespace std;

const int N = 205;

int n, a[N];

vector<int> ans;

void op (int X) {
	ans.push_back(X);
	for(int i=X;i<n;i++) {
		swap(a[i], a[i-X]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++) {
		while(a[n-1] != i) {
			op(1);
		}
		while(i && a[n-2] != i-1) {
			op(n-1);
			op(1);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto &T : ans) {
		printf("%d\n",T);
	}
}
