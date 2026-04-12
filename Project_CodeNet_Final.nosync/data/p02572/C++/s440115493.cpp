//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
// #define int unsigned long long int
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int mul1 = 1003, mul2 = 5, mul3 = 8;
const int MOD3 = 179424673, MOD2 = 982451653, MOD1 = 1190494759;
const ld EPS = 1e-9;

ll N;
ll P = 1000000007;
vector<ll> A;

int main()
{
    cin >> N;
    ll all_sum = 0;
    ll s_sum = 0;
    for (int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
        all_sum += tmp;
        s_sum += (tmp * tmp) % P;
        all_sum %= P;
        s_sum %= P;
    }

    ll mul_sum = (all_sum * all_sum + P) % P;

    ll actual_sum = (mul_sum - s_sum + P) % P;

    if (actual_sum % 2 == 0)
    {
        cout << actual_sum / 2 << endl;
    }
    else
    {
        cout << P + ((actual_sum - P) / 2) << endl;
    }

    return 0;
    
}