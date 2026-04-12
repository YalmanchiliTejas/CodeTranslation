#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define MOD (ull)(double)(1e9 + 7)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pull pair<ull, ull>
#define F first
#define S second
#define m_p make_pair
#define debug(x) cout << #x << " " << x << endl
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";cout << '\n';
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];

const long double PI = 3.141592653589793238462643383279502884197169399;

// Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))

void solve(){
	ll n, x, m;
	cin >> n >> x >> m;
	
	vll seq;
	seq.pb(x);
	set<ll> s;
	s.insert(x);
	
	while(1){
		x *= x;
		x %= m;
		if(s.find(x) != s.end())break;
		seq.pb(x);
		s.insert(x);
	}
	
	ll sum=0, cycleSize;
	vll cycleSum;
	ll c=0;
	for(int i=0 ; i<seq.size()&&i<n ; ++i){
		if(seq[i] == x){
			cycleSize = seq.size() - i;
			cycleSum.pb(seq[i]);
			for(int j=i+1 ; j<seq.size() ; ++j){
				cycleSum.pb(cycleSum.back() + seq[j]);
			}
			break;
		}
		++c;
		sum += seq[i];
	}
	
	if(c < n){
		ll left = n - c;
		ll cyclesNeeded = left / cycleSize;
		sum += cyclesNeeded * cycleSum.back();
		
		left = left % cycleSize;
		if(left)sum += cycleSum[left-1];
	}
	
	cout << sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed << setprecision(10);
	
	int tt=1;
	//cin >> tt;
	
	while(tt--){
		solve();
	}
}
