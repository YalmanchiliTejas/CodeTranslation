#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef uint64_t bu; 
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpl;
typedef vector<string> vs;
typedef vector<char> vc;
#define vb vector<bool>
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define LB lower_bound
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repr(i, a, b) for (ll i = a; i > b; i--)
#define rept(type, i, a, op, b, change) for (type i = a; i op b; i += change) //general for loop
#define cy cout << "YES"<<endl 
#define cn cout<<"NO"<<endl
#define F first
#define S second
#define PI 3.14159265358979323846
#define w(i,n) while(i<n)
#define s(v) sort(begin(v),end(v))
#define M 998244353
#define MAXN 1000001
#define MOD 1000000007
#define elif else if
//ll spf[MAXN];
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll Rselect(vector<ll> v, ll i, ll l, ll r); //finding the ith order statistic
ll partition(vector<ll> v, ll l, ll r);
void scanc(vc& v,ll n)
{
    rep(i,0,n)
    {
        char num;
        cin>>num;
        v.pub(num);
    }
}
void scanP(vpl& v,ll n)
{
    rep(i,0,n)
    {
        ll num1,num2;
        cin>>num1>>num2;
        pair p = {num1,num2};
        v.pub(p);
    }
}
template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec) //outputting a vector
{
	for (auto& i : vec)
	{
		stream << i << ' ';
	}
	stream << '\n';
	return stream;
}

template<class T>
istream& operator>>(istream& stream, vector<T>& vec) //input for vectors of fixed size
{
	for (auto& i : vec)
	{
		stream >> i;
	}
	return stream;
}

void solve();
/*
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                {
                if (spf[j]==j) 
                    spf[j] = i; 
                }
        } 
    } 
}
vector<ll> getFactorization(ll x) 
{ 
    vector<ll> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}*/
  
void scanN(vector<ll>&v,ll n)
{
    rep(i,0,n)
    {
        int num;
        cin>>num;
        v.pub(num);
    }
}
void scans(vector<string>& v,ll n)
{
    rep(i,0,n)
    {
        string s;
        cin>>s;
        v.pub(s);
    }
}

ll modfactorial(ll n,ll p)
{
    if(n>=p)
    return 0;
    ll result = 1;
    rep(i,1,n+1)
    {
        result = result*i;
        result = result%p;
    }
    return result;
}
ll MI(ll a, ll b,ll s0,ll s1)
{
    ll k = b;
    if(b == 0)
    return s0;
    else
    {
       return  MI(b,a%b,s1,s0-s1*(a/b));

    }
}
ll choose(ll a,ll b,ll c)
{
    if(a<b)
    return 0;
    ll x = modfactorial(a,c);
    ll y = modfactorial(b,c);
    ll z = modfactorial(a-b,c);
    ll y_ = MI(y,c,1,0);
    if(y_<0)
    y_ = y_+c;
    ll z_ = MI(z,c,1,0);
    if(z_<0)
    z_ = z_+c;
    ll mul = (x*y_)%c;
    mul = (mul*z_)%c;
    return mul;
}
void SOLT()
{
    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}
ll modpow(ll n,ll p,ll k)
{
    n = n%k;
    ll res = 1;
    while(p>0)
    {
        if(p%2 == 1)
        res = res*n%k;
        n = n*n%k;
        p = p/2;
    }
    return res;
}
bool isPrime(ll a) {
	for(ll i = 2; i * i <= a; ++i)
		if(a % i == 0)
			return false;
	return true;
}

bool useflushdivisible(ll a) {
	cout<<a<<endl;
	fflush(stdout);
	char sl[10];
	scanf("%s", sl);
	return sl[0] == 'y' || sl[0] == 'Y';
}
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n =n/ i;
            result =result - result / i;
        }
    }
    if (n > 1)
        result =result - result / n;
    return result;
}

int main()
{
    FAST();
   
//SOLT();
solve();
	return 0;
}


void solve()
{
    int x;
  cin>>x;
  if(x>=30)
    cout<<"Yes";
  else
    cout<<"No";
}




ll Rselect(vector<ll> v, ll i, ll l, ll r)
{
	if (l == r)
		return v[l];
	ll pivot = partition(v, l, r);
	if (pivot == i)
		return v[pivot - 1];
	else if (pivot < i)
	{
		return Rselect(v, i, pivot, r);
	}
	else
	{
		return Rselect(v, i, l, pivot - 2);
	}
}

ll partition(vector<ll> v, ll l, ll r)
{
	ll pivot_index = rand() % (r - l + 1) + l;
	swap(v[pivot_index], v[l]);
	ll i = l + 1, j = l + 1;
	while (j <= r)
	{
		if (v[j] < v[l])
		{
			swap(v[j], v[i]);
			i++;
		}
		j++;
	}
	swap(v[l], v[i - 1]);
	return i;
}
