#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	map<int, int>mp;
	rep(i, 12) {
		int e; cin >> e;
		mp[e]++;
	}
	for (auto p : mp) {
		if (p.second < 4) {
			puts("no");
			return 0;
		}
	}
	puts("yes");
}