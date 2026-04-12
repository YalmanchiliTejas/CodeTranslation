#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) (((a)+(b)-1)/(b))
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define dbg(msg, var) cerr << msg << " " << var << endl;

using namespace std;

const int MAX = 200010;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-7;

// End Template //

int main()
{sws;

    ll n, x, m;
    cin >> n >> x >> m;

    if(n<1e6){
        ll ans = x;
        for(int i=0;i<n-1;i++){
            x = (x*x)%m;
            ans+=x;
        }

        cout << ans << endl;
        return 0;

    }

    ll ans = x; n--;
    for(int i=0;i<1e5;i++){
        x = (x*x)%m;
        ans+=x; n--;
    }

    // ll pp = n;

    vl vet;
    vet.pb(x);
    while(true){
        x = (x*x)%m;
        if(x==vet[0])
            break;

        vet.pb(x);
        ans+=x; n--;
    }

    // cout << "pum = " << pp - n << endl;

    ll sum = 0;
    for(auto v: vet)
        sum+=v;

    // cout << "sum = " << sum << endl;

    ll len = vet.size();

    ll v = n/len;
    ll rest = n%len;

    ans += v*sum;

    for(int i=0;i<rest;i++){
        ans += vet[i];
    }

    cout << ans << endl;



    return 0;
}