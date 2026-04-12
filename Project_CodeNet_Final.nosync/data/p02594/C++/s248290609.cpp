#include<bits/stdc++.h>
#include <stdio.h>
#pragma GCC optimize("O2")


using namespace std;
#define newl "\n"
#define ll long long
#define ull unsigned long long

#define FORM(m)     for (auto const& x : m) cout << x.first << " : " << x.second << newl;
#define FORV(v)     for(auto &x : v) cout << x << ' '
#define FO(i,n)     for (ll i = 0; i < n; ++i)
#define FOR(i,k,n)  for (auto i = k; i <= n; ++i)
#define FORR(i,k,n) for (auto i = k; i >= n; --i)

#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); ++it)
#define mod 1000000007
#define PI 3.1415926535897932384626
#define FormulaToConvertMicrosecondsToSeconds(duration) duration / 1e+6

typedef pair<int, int>  pii;
typedef pair<ll, ll>     pl;
typedef vector<int>      vi;
typedef vector<ll>       vl;
typedef vector<pii>    vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

void getVecIndex(vector<int> v, int K) {
	auto it = find(all(v), K);

	if (it != v.end()) {
		cout << distance(v.begin(), it);
	}
	else
		cout << -1;
}

bool isPrime(int num) {
	if (num <= 1)
		return false;

	if (num == 2)
		return true;

	if (num % 2 == 0)
		return false;

	int counter = 3;

	while ((counter * counter) <= num) {
		if (num % counter == 0) {
			return false;
		} else {
			counter += 2;
		}
	}

	return true;
}

ull fpow(ull base, ull exp) {
	base %= mod;
	ull result = 1;
	while (exp > 0) {
		if (exp & 1) result = (static_cast<ull>(result * base)) % mod;
		base = (static_cast<ull>(base * base)) % mod;
		exp >>= 1;
	}
	return result;
}

ll binarySearch(int a[], int l, int r, int x)
{
	while (l <= r)
	{
		int mid_index = l + (r - l) / 2;

		if (a[mid_index] == x)
			return mid_index;
		else if ( x > a[mid_index])
		{
			l = mid_index + 1;
		}
		else if ( x < a[mid_index])
		{
			r = mid_index - 1;
		}
	}
	return -1;
}

void permuteString(string s)
{
	sortall(s);

	do {
		cout << s << newl;
	} while (next_permutation(all(s)));

}

void permuteArray(int array[], int n)
{
	sort(array, array + n);

	do {
		FOR(i, 0, n - 1)
		cout << array[i] << ' ';

		cout << newl;
	} while (next_permutation(array, array + n));
}

void permuteVector(vector<int> v)
{
	sortall(v);

	do {
		FORV(v);

		cout << newl;
	} while (next_permutation(all(v)));
}


ull largestPrimeFactor(ull n)
{
	for (int factor = 2; factor * factor <= n; ++factor)
	{
		while (n % factor == 0 and n != factor)
			n /= factor;
	}

	return n;
}

ull numberOfDivisors(ull n)
{
	ull divisors = 0;
	if (n == 1)
		return 1;


	for (ull i = 1; i * i <= n; ++i) // we need to CHECK at least sqrt(n) TIMES (inclusive) if 'i' is a divisor of n.
	{
		if (n % i == 0)
		{
			divisors += 2;
		}
	}
	return divisors;
}

// greatest common divisor
ll gcd( ll a, ll b )
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd( b, a % b );
	}
}
// least common multiplication
ll lcm (ll a, ll b)
{
	return (a * b) / gcd(a, b);
}


// ∈




//=======================
void solve()
{

	int x; cin >> x;
	if (x >= 30) cout << "Yes";
	else cout << "No";

}

/* TESTS:



*/

int32_t main()
{
	//--------------------------------
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	auto t1 = std::chrono::high_resolution_clock::now();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve(); cout << newl;
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	cerr << "\nDuration of the algo: " << FormulaToConvertMicrosecondsToSeconds(duration) << " secs" << newl << newl;
	return 0;
}