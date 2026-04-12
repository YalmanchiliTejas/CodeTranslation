//--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR
//--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR

// Important header files
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;



#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define REDL(a ,n) vll a(n);for(ll i=0;i<n;i++) cin>>a[i];
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(X)  X.begin() ,  X.end()
#define reset(X) memset(X, 0, sizeof(X))
#define f(a,b,c) for(ll a=b;a<c;a++)
//-----------------------------TEMPLATES------------------TEMPLATES---------------------------TEMPLATES---------------------------------
//-----------------------------TEMPLATES------------------TEMPLATES---------------------------TEMPLATES---------------------------------



//--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF----------------------------TYPEDEF
//--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF----------------------------TYPEDEF

typedef  long long ll;
typedef complex<long double> cd;
typedef __float128 ld;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;
typedef vector<ll> vll;
// Declaring ordered_set
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

//--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS
//--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS

const ll INF=LLONG_MAX-100;
//const ll mod=1000000007;
const ll mod=998244353;





//------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT



// To find GCD of a and b

// To compute x raised to power y under modulo m
ll power(ll x, ll y, ll m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m)
{
    ll g = __gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        return power(a, m-2, m);
    }
}

// To compute x^y under modulo m
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}


//code to  look for-----------------------------------------------------------------
/*
const ll MAXN=1e6+100;
ll  prime[MAXN];
bool is_composite[MAXN];
ll phi[MAXN];

void sieve (ll n) {
	phi[1] = 1;
	ll primes_count=0;
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime[primes_count]=i;
			primes_count++;
			phi[i] = i - 1;					//i is prime
		}
		for (ll j = 0; j < primes_count && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
			}
		}
	}
}*/



void fft(vector<cd>&  a , bool invert)
{
    ll n=a.size();
    ld PI=acos(-1);
    for(ll i=1,j=0;i<n;i++)
    {
        ll bit=n>>1;
        for(;j&bit;bit>>=1)
        {
            j^=bit;
        }
        j^=bit;
        if(i<j)
            swap(a[i], a[j]);
    }
    for(ll i=2;i<=n;i<<=1)
    {
        double ang=2*PI/i*(invert?-1:1);
        cd wn(cos(ang), sin(ang));
        for(ll j=0;j<n;j+=i)
        {
            cd w(1);
            for(ll k=j;k<j+i/2;k++)
            {
                cd u=a[k], v=a[k+i/2]*w;
                a[k]=u+v;
                a[k+i/2]=u-v;
                w*=wn;
            }
        }

    }
    if(invert)
    {
        for(ll i=0;i<n;i++)
            a[i]/=n;
    }

}
vector<ll>  multfft(vector<ll> a, vector<ll>b)
{
    vector<cd> fa(all(a)), fb(all(b));
    ll n=1;
    while(fa.size()+fb.size()>n)
        n*=2;
    fa.resize(n);
    fb.resize(n);
    vector<ll> result(n);
    fft(fa,false);
    fft(fb,false);
    for(ll i=0;i<n;i++)
        fa[i]*=fb[i];
    fft(fa,true);
    for(ll i=0;i<n;i++)
        result[i]=round(fa[i].real());
    return result;

}

//----------------------MAIN______________________________MAIN__________________MAIN

signed main()
{


    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
   cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cout.tie(0);
    //----------------  --------------------------------------------------------------------------------
    int n;
    cin>>n;
    REDL(a,n);
    multiset<ll> data;
    for(auto i:a)
    {
        auto k=data.lower_bound(i);
        if(k==data.begin())
        {
            data.insert(i);
        }
        else
        {
            k--;
            ll l=*k;
            data.erase(data.find(l));
            data.insert(i);
        }
    }
    cout<<data.size();
    //-----------00;--------------------------
    //-----------------------------------------------------------


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cerr <<endl<<"Time in microseconds:" <<duration.count() <<endl<<"Time in seconds:"<<duration.count()/(1000000.0)<< endl;
}
