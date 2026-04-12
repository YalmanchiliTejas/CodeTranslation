#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}());
const ll mod=100000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

const int maxn = 200023;
int T;
ll n;
ll x;
ll y;
string str;

int main(int argc, char const *argv[])
{
#ifdef indiewar
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//    cin >> T;
    T =1;
    while(T--)
    {
        cin >> str;
        if(str == "AAA" || str == "BBB")
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }


    }
    return 0;
}