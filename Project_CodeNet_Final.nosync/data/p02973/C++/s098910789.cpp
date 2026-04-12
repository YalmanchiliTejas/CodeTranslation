/*
Original problem: https://atcoder.jp/contests/abc134/tasks/abc134_e
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll mod = 1e9+7;

namespace SOLVE {
    void main() {
        int n, temp;
		cin >> n;
		multiset<int> s;
		multiset<int>::iterator itr; 
		REP(i,0,n) {
			cin >> temp;
			itr = s.lower_bound(temp); // find the first number that is temp, --
			
			if (itr == s.begin()) {
				s.insert(temp);
			} else {
				itr--;
				// cout << i << ' ' << "erase" << *itr << endl;
				s.erase(itr);
				s.insert(temp);
			}
		}
		cout << s.size() << endl;
    }
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}