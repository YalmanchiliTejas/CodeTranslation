 //
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define f first
#define s second
#define what_is(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

const int N = 1000005;

void set_file_io(string in, string out)
{
    freopen((in+".in").c_str(), "r", stdin);
    freopen((out+".out").c_str(), "w", stdout);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //set_file_io("input", "output");
    int n;
    cin >> n;
    ll sum = 0, sqr = 0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        sum = (sum + x) % MOD;
        sqr = (sqr + x*x) % MOD;
    }
    cout << ((sum*sum + MOD - sqr) % MOD) * ((MOD+1)/2) % MOD;
    return 0;
}
