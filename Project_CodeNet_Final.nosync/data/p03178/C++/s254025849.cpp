//////////////////////////////////////
////   Author: ABHINASH GIRI      ////
/////////////////////////////////////
//cout<<"Case #"<<l<<":"<<x<<nl;

#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI (2*acos(0.0))
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pos_rt_stbt(x)   (__builtin_ffsll(x))   // return position of rightmost set bit ( 1 indexing ) pos_rt_stbt(10) = 2 ( 1010 )
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            int t; cin>>t; while(t--)
#define nl "\n"
#define all(v) (v).begin(),(v).end()
#define clr(v) memset(v,0,sizeof(v));
#define sqr(x) ((x) * (x))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<vll> vvll;
typedef vector<unsigned long long int> vull;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<string, string>> vpss;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7 ;
const long long int MOD =  998244353;
//----------------------------------------------------------------------------------------------------------------------
// Debug
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef ABHI
    eni( != ) cerr << boolalpha << i; ris;
    }
    eni( == ) ris << range(begin(i), end(i));
    }
    sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
    sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#else
    sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
    char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
    vector<char*> v({token});
    while (token = strtok(NULL, ", ")) v.push_back(token);
    return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*> args) { cerr << "\b\b "; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
    debug() << " [" << args.back() << ": " << H << "] ";
    args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifdef ABHI
#define deb(...) { debugg(tokenizer(harg(__VA_ARGS__, \b\t-->Line)), __VA_ARGS__, __LINE__); cerr << endl;}
#else
#define deb(...) { }
#endif
/// --------------------------------------------------------------------------------------------------------------------

#define ptvs(v) for(auto &item :v) cout<<item<<" ";cout<<"\n";
#define ptp(v) for(auto &item :v) cout<<item.first<<" ----> "<<item.second<<"  "; cout<<"\n"
#define ptv(v) for(auto &item :v) cout<<item<<"\n"
#define pt(x) cout<<((x))<<"\n";
#define pt2(x,y) cout<<(x)<<" "<<(y)<<"\n";
#define cinvll(v,start,end) vll v(end+1);for(auto i=start;i<=end;i++) {cin>>v[i];}
//***********************************************************************************************
//Sorting Comparators

// sorts in ascending order on first and on second ( if first equals)
template <typename T>
bool  asc(pair<T, T>&a, pair<T, T>&b)
{
    if (a.first == b.first)
    {return a.second > b.second;}
    return a.first < b.first;
}

// sorts in descending order on first and on second ( if first equals)
template <typename T>
bool desc(pair<T, T>&a, pair<T, T>&b)
{
    if (a.first == b.first)
    {return a.second > b.second;}
    return a.first > b.first;
}
//***********************************************************************************************

// Fast Exponentiation power(a,b) ==> a to the power b
template <typename T>
T  power(T  a, T  b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else {
        T  res = (power(a, b / 2));
        if (b % 2)
        {
            return (res * res * a);
        }
        else
        {return res * res;}
    }
}

// Fast Modular Exponentiation  power(a,b,m) ==> (a to the power b) modulo m
template <typename T>
T  power(T  a, T  b, T modulo)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else {
        T  res = (power(a, b / 2, modulo) % modulo);
        if (b % 2)
        {
            return ((((res % modulo) * (res % modulo)) % modulo) * (a % modulo)) % modulo;
        }
        else
        {return ((res % modulo) * (res % modulo)) % modulo;}
    }
}
// G C D
template <typename T>
T  gcd(T  a, T  b) {
    if (b == 0)
    {return a;}
    return gcd(b, a % b);
}
// L C M
template <typename T>
T lcm(T p, T q)
{return (p * q) / gcd<T>(p, q);}

//Prime factorisation
template <typename T>
void primefactorise(T n, vector<T>&vec)
{
    while (n % 2 == 0) {
        vec.emplace_back(2);
        n = n / 2;
    }
    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            vec.emplace_back(i);
            n = n / i;
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        vec.emplace_back(n);
    }
}
// All factors of a number in O(sqrt(n))
template <typename T>
void all_factor(T n, vector<T>&vec)
{
    for (auto i = 1; i <= sqrt(n) ; ++i) {
        if (n % i == 0)
        {
//          Factors occurs in pairs
            vec.emplace_back(i);
            if (i != (n / i))
            {
                vec.emplace_back(n / i);
            }

        }
    }
}

ll mod_inv(ll a) {    return (power<ll>(a, mod - 2, mod)) % mod;    }

void factorial(vll &fact, ll n)
{
    fact.resize(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n ; ++i)
    {
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
        //cout<<" fact "<<i<<" "<<fact[i]<<nl;
    }
}

ll ncr(ll n, ll r, vll fact)
{
    if (n < r or n < 0 or r < 0)
    {
        return 0;
    }
    return fact[n] % mod * mod_inv(fact[r]) % mod * mod_inv(fact[n - r]) % mod % mod % mod;
}


vll fib;
ll fibonacci(ll n)
{
    if (n <= 2)
    {
        return fib[n];
    }
    if (fib[n] != -1)
    {
        return fib[n];
    }
    ll k;
    if (n & 1)
    {
        k = (n + 1) / 2;
        fib[n] = fibonacci(k) * fibonacci(k) + fibonacci(k - 1) * fibonacci(k - 1);
    }
    else
    {
        k = n / 2;
        fib[n] = (2 * fibonacci(k - 1) + fibonacci(k)) * fibonacci(k);
    }
    return fib[n];
}
ll d;
ll dp[10009][2][101];
ll digi_sum(string& r,ll pos,ll tight,ll m,ll curr_sum)
{
    if(pos==r.length())
    {
        if(curr_sum%d==0)
        {
//            cout<<s<<" returned 1 "<<nl;
            return 1;
        }
        return 0;
    }
    if(dp[pos][tight][m]!=-1)
    {
//        cout<<" returned dp "<<dp[pos][tight][m]<<" with m= "<<m <<nl;
        return dp[pos][tight][m];
    }
    if(tight)
    {
        ll res=0;
        for (ll i = 0; i <=r[pos]-'0' ; ++i)
        {
            ll a = curr_sum+i;
//            cout<<" selected pos "<<pos<<" "<<s[pos]<<" tight "<<tight <<nl;
            if(i==r[pos]-'0')
            {
                res = ((res%mod) + (digi_sum(r,pos+1,1,(d-a%d)%d,a)%mod))%mod;
            }
            else res = ((res%mod) + (digi_sum(r,pos+1,0,(d-a%d)%d,a)%mod))%mod;
        }
//        cout<<" answer for pos "<<pos<<" "<<dp[pos][tight]<<nl;
         dp[pos][tight][m]=res;
        return dp[pos][tight][m];
    }
    else
    {
        ll res=0;
        for (int i = 0; i <=9 ; ++i)
        {
            ll a = curr_sum+i;
//            cout<<" selected pos "<<pos<<" "<<s[pos]<<nl;
            res = ((res%mod) + (digi_sum(r,pos+1,0,(d-a%d)%d,a)%mod))%mod;
        }
//        cout<<" answer for pos "<<pos<<" "<<dp[pos][tight]<<nl;
        dp[pos][tight][m]=res;
        return dp[pos][tight][m];
    }
}
int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timer, end_timer;
    start_timer = std::chrono::high_resolution_clock::now();
    bool show_time = false;  //  change it to true when needed;
    /* Building Block */
    fast;
    string k;
    cin>>k>>d;
    memset(dp,-1,sizeof(dp));
    ll a1 = digi_sum(k,0,1,0,0);
    pt((a1-1+mod)%mod);

    end_timer = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_timer - start_timer).count();
    if (show_time)
    {cout << "\nElapsed Time: " << elapsed_time << "ms\n";}

    return 0;
}


