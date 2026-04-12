#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	int k;
	for(int i = 0; i < q; i++) {
		scanf("%d", &k);
		printf("%ld\n", lower_bound(a.begin(), a.end(), k) - a.begin());
	}
}

