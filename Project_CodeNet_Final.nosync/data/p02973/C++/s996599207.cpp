#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

typedef multiset<int> mset;

mset mts;

int n, a;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		if(mts.empty()) mts.insert(a);
		else {
		    mset :: iterator it = mts.lower_bound(a);
			if(it == mts.begin()) mts.insert(a);
			else {
				it --;
				mts.erase(mts.find(* it));
				mts.insert(a);
			} 
	    }
	}
	printf("%d\n", (int) mts.size());
	return 0;
}
