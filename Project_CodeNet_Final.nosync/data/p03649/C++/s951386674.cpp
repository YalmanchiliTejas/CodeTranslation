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
const int maxN = 1e6 + 7;
const ll mod = 1e18 + 7;

int n;
ll arr[maxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	REP(i, n) cin>>arr[i];
	//sort(arr, arr + n);
	ll sum = 0, ans = 0;
	while (true) {
		REP(i, n) sum += (arr[i] / n);
		ans += sum;
		REP(i, n) {
			ll x = (arr[i] / n);
			arr[i] -= x * n;
			arr[i] += (sum - x);
		}
		//REP(i, n) cout<<arr[i]<<" ";
		//cout<<endl;
		bool pom = false;
		REP(i, n) if (arr[i] >= n) pom = true;
		if (!pom)
			break;
		sum = 0;
	}
	cout<<ans;
	return 0;
}
