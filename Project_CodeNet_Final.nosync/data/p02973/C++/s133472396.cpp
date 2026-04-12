#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5;

int n, a[MAXN], ans;
multiset<int> leaf;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; ++i){
		if(leaf.empty()){
			ans++;
		}else{
			auto p = leaf.lower_bound(a[i]);
			if(p == leaf.begin()){
				ans++;
			}else{
				p--;
				leaf.erase(p);
			}
		}
		leaf.insert(a[i]);
	}
	printf("%d\n", ans);
}