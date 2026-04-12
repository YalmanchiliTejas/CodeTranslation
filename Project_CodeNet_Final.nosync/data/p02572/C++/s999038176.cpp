#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define PI acos(-1.0)
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define MOD 1000000007
#define MOD1 998244353
#define ep 0.000000001
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, 1};
int dy4[] = {1, -1, 1, -1};
//#define fio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
    ll n; 
    cin>>n; ll a[n+1], s, sum=0, p=0, ans, q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        sum%=MOD;
        p+=((a[i]*a[i])%MOD);
        p=p%MOD;
    }
    s=sum*sum; s%=MOD;
    q=s-p; 
    if(q<0)q=MOD-(abs(q)%MOD);
    ll x = 1, b=2, po=MOD-2;
        b=(b%MOD);
        while (po>0){
            if(po & 1)
            x=(x*b) % MOD;
            po=po>>1;
            b=(b*b) % MOD;
        }
    ans=((q%MOD)*(x%MOD))%MOD;
    cout<<ans<<endl;
    return 0;
}
//https://thebestoffersintheweb.com/redirect/57a764d042bf8/
