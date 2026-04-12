/* 
	Author: ankrypt
*/


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

ll N;
ll arr[25];

int main() {
	scanf("%lld", &N);
	for(int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	ll cnt = 1;
	for(int i = 1; i < N; i++) {
		int flag = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(arr[j] > arr[i]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			cnt++;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}
/*
	Powered by Buggy Plugin
*/
