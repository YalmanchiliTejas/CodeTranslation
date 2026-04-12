//#pragma GCC optimize("O3")

#include <bits/stdc++.h>
//#include <ctime>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(n) FOR(O, 1, (n))
#define pb push_back
#define f first
#define s second
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<piii> viii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 500100, MAXK = 20;
const ll MOD = 1e9+7;
const ll INF = 1e16;
const ld PI = asin(1) * 2;

void setIO () {
    FAST_IO;
}

void setIO (string s) {
    setIO();
 	freopen((s+".in").c_str(),"r",stdin);
 	freopen((s+".out").c_str(),"w",stdout);
}



int main() {
    setIO();
	//setIO("lmio_1991_3e1_seka_01");

    int x; cin >> x;
    if (x >= 30) cout << "Yes\n";
    else cout << "No\n";

	return 0;
}
