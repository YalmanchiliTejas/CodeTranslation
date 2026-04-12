#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
using namespace std;
#define ll long long

int main() {
	int N; cin >> N;
	vector<ll> s(N);
	for(int i=0; i<N; ++i) cin >> s[i];
	ll ans=0;
	for(int i=1; i<N/2; ++i){
	    ll now=0;
	    for(int a=1; i*a<N-1-i && ((N-1)%i>0 || i*a<N/2); ++a){
	        now += s[i*a]+s[N-1-i*a];
	        ans=max(now, ans);
	    }
	}
	cout << ans << endl;
	return 0;
}
