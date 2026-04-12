#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll mod = 1e9+7;
const double error = 1e-7;
const double PI = acos(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise\n"
#define tham getchar()
mt19937_64 rng((unsigned int) chrono::system_clock::now().time_since_epoch().count());

inline ll MOD(ll x, ll m = mod)
{
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e8+5;
const ll infl = 1e15;
const int nmax = 2e6+5;
///====================== template =========================

int LIS(vector<int> a, int n) {
	vector<int> lis;
	for(int i=0; i<n; ++i) {
		vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), a[i]);
		if(it == lis.end()) lis.push_back(a[i]);
		else *it = a[i];
	}
	return (int) lis.size();
}

int main(){
    FASTIO;
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    reverse(input.begin(), input.end());
    int res = LIS(input, (int) input.size());
    cout << res << "\n";

    return 0;
}
