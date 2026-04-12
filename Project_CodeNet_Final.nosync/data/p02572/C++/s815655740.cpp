#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;

int pow(int a, int b, int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

int modinv(int k)
{
    return pow(k, MOD-2, MOD);
}

int32_t main() {
    fast;
    int n;

    cin >> n;

    int sum = 0;
    int a[n];
    f(i,0,n)    cin >> a[i], sum += a[i] , sum %= MOD;;


    int ans = 0;

    f(i,0,n){
        int x = ((sum - a[i])%MOD + MOD)%MOD;
        ans = (ans + (x * a[i])%MOD)%MOD;
    }

    ans = (ans * modinv(2))%MOD;

    cout << ans << "\n";
}