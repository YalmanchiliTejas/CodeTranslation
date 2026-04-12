/// You just can't beat the person who never gives up
/// ICPC next year


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
#define mod             1000000007
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
void offset(vector<int>&a,int x) {
    for(int i = 0; i < sz(a);i++) {
        a[i] = x;
    }
}
struct cmp {
    bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const {
        return lhs.ff * rhs.ss < lhs.ss * rhs.ff;
    }
//for map<pii,int>
};


// auto cmp = [](pair<int,int>a,pair<int,int>b) {if(a.first==b.first)return a.second>b.second;
//      else return a.first > b.first;
//  };
//  multiset<pair<int,int>,decltype(cmp)>fc(cmp);
double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    //unordered_map<long long, int, custom_hash> safe_map;
};

const int MAXN = 2e5+ 10;

#define int long long
bool cmps(pair<int,int>p1,pair<int,int>p2) {
    return p1.ss > p2.ss;
}
int32_t main() {
    fio
    int x;
    cin >> x;
    if(x >= 30) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    };

    cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;


}




