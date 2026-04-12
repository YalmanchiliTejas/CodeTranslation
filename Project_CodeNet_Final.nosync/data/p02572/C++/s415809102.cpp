#include<bits/stdc++.h>
using namespace std;

#define gcd(a,b)		__gcd(a,b)
#define lcm(a,b)		(a*b)/gcd(a,b)
#define ff              first
#define ss              second
#define int             long long
#define float			double
#define pb              emplace_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vc				vector<char>
#define vb				vector<bool>
#define vf				vector<float>
#define vs				vector<string>
#define mii             map<int,int>
#define seti			set<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             INT64_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(x)			x.begin(),x.end()
#define digits(x)		floor(log10(x))+1
#define FIO				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

template<class T>
void printV(vector<T> a) {
	for (auto v : a)cout << v << " ";
}
template<class T>
void readV(vector<T>& a) {
	int n = a.size(); for (int i = 0 ; i < n ; i++)cin >> a[i];
}
template<class T>
void printA(T* a , int n) {
	for (int i = 0; i < n  ; i++)cout << a[i] << " ";
}
template<class T>
void readA(T* a , int n) {
	for (int i = 0 ; i < n ; i++)cin >> a[i];
}
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
void run_time() {
	cout << endl;
	cout << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl;
	return;
}
template<typename T>
class dsu {
private:
	map<T, T> parent;
	map<T, int> size;

	T root( T x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
public:
	dsu(vector<T> s) {
		for (T node : s) {
			parent[node] = node;
			size[node] = 0 ;
		}
	}
	bool find(T x , T y) {
		return root(x) == root(y);
	}
	void join(T x , T y) {
		T i = root(x);
		T j = root(y);
		if (i == j) {
			return;
		}
		if (size[i] < size[j]) {
			parent[i] = j;
			size[j] += size[i];
		}
		else {
			parent[j] = i;
			size[i] += size[j];
		}
	}
};
class BIT {
private:
	int* FT;
	int n;
public:
	void updateBIT(int index , int val) {
		index += 1;
		while (index <= n) {
			FT[index] += val;
			index += (index & (-index));
		}
	}

	int getSum(int index) {
		index += 1;
		int sum = 0 ;
		while (index > 0) {
			sum += FT[index];
			index -= (index & (-index));
		}
		return sum;
	}


	BIT(int* a , int v) {
		n = v ;
		FT = new int[n + 1];
		for (int i = 1 ; i <= n ; i++) {
			FT[i] = 0 ;
		}
		for (int i = 0 ; i < n ; i++) {
			updateBIT(i, a[i]);
		}
	}
};
int nCr(int n , int r ) {
	int p = 1, k = 1;

	if (n - r < r ) {
		r = n - r;
	}
	if (r != 0) {
		while (r != 0) {
			p *= n ;
			k *= r ;
			int m = __gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else {
		p = 1;
	}
	return p ;
}
int modPower(int x, int y , int p) {
	//Used to calculate (x^y)%p
	int res = 1;
	if (y == 0) {
		return 1;
	}

	x = x % p;
	if (x == 0) {
		return 0  ;
	}

	while (y > 0) {
		if (y & 1) {
			res = (res * x) % p;
		}

		y >>= 1;
		x = (x * x) % p;
	}
	return res ;
}
bool isPrime(int n) {
	if (n == 0 or n == 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	for (int i = 2 ; i <= sqrt(n) ; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int32_t main() {
	FIO;

	int n ;
	cin >> n ;
	vi a(n);
	int sum = 0 ;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int ans = 0 ;
	for (int i = 0 ; i < n ; i++) {
		sum -= a[i];
		ans = ans + (((a[i] % mod) * (sum % mod)) % mod);
	}
	ans %= mod;
	cout << ans;


	return 0;
}
