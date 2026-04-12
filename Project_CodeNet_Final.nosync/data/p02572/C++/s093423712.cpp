#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define bash int n; cin >> n; int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
const int mod = 1e9 + 7;
const int MAX = 2e6 + 9;
const double pi = 3.141592653589793238460;
using namespace std;

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...)
#endif

bool is_pal (string s){
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) ? 1 : 0;
}

int power(int x,int y, int res = 1) {
    x %= mod; 
    for( ; y ; y >>= 1LL ) {
        if(y & 1LL){ 
            res = res * x % mod;
        }
        x = x * x % mod;
    }
    return res;
}

int modInv (int x){
    return ( power(x,mod-2) + mod ) % mod;
}

int fact[MAX], inv[MAX];

void compFact(void){
    fact[0] = fact[1] = inv[1] = inv[0] = 1;
    for (int i = 1; i < MAX; i++) { 
        fact[i] = (fact[i - 1] * i % mod + mod) % mod; 
    } 
}

void compInv(void){
    for(int i = 2; i < MAX; ++i){
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod + mod) % mod;
    }
}

int nCr (int n, int r){
    if(n < r || n < 0){
        return 0;
    }
    return ( ( ( ( fact[n] % mod ) * ( inv[fact[n-r]] % mod ) ) % mod ) * ( inv[fact[r]] % mod ) + mod) % mod; 
}

int factMod(int n, int res = 1) {
    while (n > 1) {
        res = (res * ((n/mod) % 2 ?  mod-1 : 1)) % mod;
        for (int i = 2; i <= n % mod; ++i)
            res = (res * i) % mod;
        n /= mod;
    }
    return res % mod;
}

int max (int x, int y){
    return x>y ? x : y;
}

int min (int x, int y){
    return x<y ? x : y;
}

int lcm (int x, int y){
    return (x*y)/__gcd(x,y);
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N;

bool under_bound(int x, int y){
    return x >= 0 && y <= 0 && x < N && y < N;
}

bool prime[MAX]; 

void SieveOfEratosthenes(int n){
     
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p < n; p++){ 
        if (prime[p] == true){ 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
         } 
    }  
}

multiset<int> A;

void primeFact(int n){
    while (n % 2 == 0)  {  
        A.insert(2); 
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  {  
        while (n % i == 0)  {  
            A.insert(i); 
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        A.insert(n);  
}

int spf[MAX];

void SieveOfEuler(){ 
    spf[1] = 1; 
    
    for (int i=2; i < MAX; i++) 
    spf[i] = i; 
  
    for (int i=4; i < MAX; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i < MAX; i++){ 
        if (spf[i] == i){ 
            for (int j = i*i; j < MAX; j += i) 
                  if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

map < pair<int, int>, int > factFreq;

void getFactorization(int x) {
    while(x > 1){
        int pt = spf[x], f = 0;
        while (x % pt == 0){
            x /= pt;
            f++;
            factFreq[{pt,f}]++;
        }
    }
}

vector <vector <int> > mul (vector <vector <int> > &A, vector < vector<int> > &B){
	int r = A.size(), c = A[0].size() ;
	vector <vector <int> > C(r, vector <int> (c, 0));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			for(int k = 0; k < c; k++){
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= mod;
			}
		}
	}
	return C;
}

vector <vector <int> > powerMatrix(vector < vector <int> > &A, int n){
	vector <vector <int> > res(A.size(), vector <int> (A[0].size(), 0));
	for(int i = 0; i < res.size(); i++){
		 res[i][i] = 1;
	}
	while(n){
		if(n & 1){
			res = mul(res, A);
		}
		A = mul(A, A);
		n = n>>1;
	}
	return res;
}

int ans;

void solve(void){
	int n;
	cin >> n;
	int a[n + 1];
	a[0] = 0;
	int pre[n+1] = {0};
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
		pre[i] %= mod;
	}
	for(int i = 1; i <= n; i++){
		ans += (a[i] * (pre[n] - pre[i] + mod)) % mod;
		ans %= mod;
	}
	cout << ans ;
	// string a, b;
	// cin >> a >> b;
	// int mx = 1e18;
	// for(int i = 0; i + b.size() < a.size(); i++){
		// ans = 0;
		// int k = 0;
		// for(int j = i; j < i + b.size(); j++){
			// ans += (a[j] != b[k++]);
		// }
		// assert(k == b.size());
		// mx = min(mx, ans);
	// }
	// cout << mx << endl;
}
signed main() {
fio;
int t = 1;
// cin >> t;    
	while(t--)
    solve();

    return 0;
}
