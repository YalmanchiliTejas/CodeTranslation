#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long int

int n;
int a[100005];
multiset<int> ms;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++){
		if(!ms.size()) {
			ms.insert(a[i]);
			continue;
		}
		multiset<int>::iterator it = ms.lower_bound(a[i]);
		if(it == ms.begin()) ms.insert(a[i]);
		else{
			it --;
			ms.erase(it);
			ms.insert(a[i]);
		}
	}
	cout << ms.size();
}