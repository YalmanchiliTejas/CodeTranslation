#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pii, int> para;
const int inf = 1e9 + 7;
const int maxN = 1e6 + 5;

int n, arr[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	RI(i, n) cin>>arr[i];
	for (int i = n; i >= 1; i -= 2) {
		cout<<arr[i]<<" ";
	}
	int start = 1;
	if (n % 2 == 1) start++;
	for (int i = start; i <= n; i += 2) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
