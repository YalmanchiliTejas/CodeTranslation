#include <bits/stdc++.h>
#define ll long long
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
using namespace std;
const int tINF = (int)INT_MAX;
const long long lINF = (long long)LLONG_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef DEBUG
			assert(freopen("inp", "r", stdin));
			assert(freopen("out", "w",stdout));
	#else
			#define cerr if(false)cerr
	#endif
    ll n,m ;
    cin >> n >> m;
    if(n == m)
        cout << "Yes\n";
    else
        cout << "No\n";
   cerr << "Time execute: " << (double)clock() / (double)CLOCKS_PER_SEC 
    << " sec" << endl;
}