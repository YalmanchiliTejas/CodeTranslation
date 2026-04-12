#include    <bits/stdc++.h>
#define     MOD 1000000007
#define     ll long long int
#define     pll pair<ll, ll>
#define     pb push_back
#define     endl "\n"
#define     f first
#define     s second
#define     fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll power(ll x, ll y) { ll ans = 1; x %= MOD; while (y) {if (y & 1)ans = (x * ans) % MOD; x = (x * x) % MOD; y >>= 1;} return ans;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

void buildTree(long long int* segTree, vector<int>& arr, int i, int lo, int hi) {
	if (lo == hi) {
		segTree[i] = arr[lo];
		return;
	}
	int mid = lo + (hi - lo) / 2;

	buildTree(segTree, arr, 2 * i + 1, lo, mid);
	buildTree(segTree, arr, 2 * i + 2, mid + 1, hi);
	segTree[i] = segTree[2 * i + 1] & segTree[2 * i + 2];
}

long long int findMin(long long int* segTree, int lo, int hi, int qlo, int qhi, int i) {

	if (qlo <= lo && qhi >= hi)
		return segTree[i];

	if (qlo > hi || qhi < lo)
		return 0;

	int mid = lo + (hi - lo) / 2;

	return findMin(segTree, lo, mid, qlo, qhi, 2 * i + 1) & findMin(segTree, mid + 1, hi, qlo, qhi, 2 * i + 2);
}

vector<int> andQueries(vector<int> numbers, vector<vector<int>> queries) {
	int n = numbers.size();
	int q = queries.size();

	vector<int> op(q);

	long long int segTree[4 * n];

	for (int i = 0; i < 4 * n; i++)
		segTree[i] = INT_MAX;
	debug(numbers);
	buildTree(segTree, numbers, 0, 0, n - 1);
	
	for(int i = 0; i < 4*n; i++)
	    cout << segTree[i] << endl;

	for (int i = 0; i < q; i++) {
		int l = queries[i][0], r = queries[i][1], s = queries[i][2], t = queries[i][3];
		//debug(queries[i]);
		int ans = 0;
		while (l + s - 1 <= r) {
		    int sum = findMin(segTree, 0, n - 1, l - 1, l + s - 2, 0);
		    debug(sum);
			if (sum >= t) {
				ans++;
			}
			l++;
		}

		op[i] = ans;
	}

	return op;
}

void solve() {
	ll n, q;
	cin >> n;
	vector<int> first (n);

	for (int i = 0; i < n; i++)
		cin >> first[i];

	cin >> q;
	vector<vector<int>> queries(q, vector<int>(4));
	for (int i = 0; i < q; i++)
		for (int j = 0; j < 4; j++)
			cin >> queries[i][j];

    //debug(queries);
	vector<int> ans = andQueries(first, queries);
    for(int i : ans)
        cout << i << endl;
	//debug(ans);
}

int main() {

	fastio;
	int n;
	cin >> n;
	if(n >= 30) {
	    cout << "Yes\n";
	} else {
	    cout << "No\n";
	}
}