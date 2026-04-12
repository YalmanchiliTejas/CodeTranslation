/* 
	Author: ankrypt
*/


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

ll N;
ll arr[100005];
multiset<int> ms;

int main() {
	scanf("%lld", &N);
	for(int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	for(int i = 0; i < N; i++) {
		multiset<int> :: iterator itr = ms.lower_bound(arr[i]);
		if(itr == ms.begin()) {
			ms.insert(arr[i]);
		}
		else {
			itr--;
			ms.erase(itr);
			ms.insert(arr[i]);
		}
	}
	// multiset<int> :: iterator it;
	// for(it = ms.begin(); it != ms.end(); it++) {
	// 	cout << *it << " ";
	// }
	int ans = ms.size();
	printf("%d\n", ans);
	return 0;
}
/*
	Powered by Buggy Plugin
*/
