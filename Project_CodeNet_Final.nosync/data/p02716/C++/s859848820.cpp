#include <bits/stdc++.h>
using namespace std;

#define int ll
#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}

const int MOD = 1E9 + 7, MAXN = 5E5 + 1000;

ll pow(ll x, ll y) {
	if(y == 0)
	return 1;
	ll temp = pow(x, y/2);
	temp = (temp*temp)%MOD;
	if(y%2 == 1)
		temp *= x;
	return temp%MOD;
}


int pr[MAXN], dp[MAXN];
vi primes;

int32_t main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	dp[1] = max(a[0], a[1]);
	int arr[n];
	arr[0] = a[0];
	for(int i = 2; i < n; i += 2) {
		arr[i] = a[i] + arr[i - 2];
	}
	for(int i = 2; i < n; i++) {
		if(i%2 == 0)
			dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
		else {
			dp[i] = a[i] + dp[i - 2];
			dp[i] = max(dp[i], arr[i - 1]);
		}
	}
	cout << dp[n - 1];
}