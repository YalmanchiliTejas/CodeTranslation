#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define int long long

const int N = 101;

int n , a[N] ,sum;

void read() {
	scanf("%lld",&n);
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
}

bool pd() {
	for(int i = 1;i <= n;i ++) if((a[i] + sum) > n - 1) return 0;
	return 1;
}

main() {
	read();
	while(1) {
		for(int i = 1;i <= n;i ++) {
			if((a[i] + sum) > n - 1) {
				int p = (a[i] + sum) / n;
				a[i] -= p * n + p;
				sum += p;
			}
		}
		if(pd()) break;
	}
	cout<<sum<<endl;
}