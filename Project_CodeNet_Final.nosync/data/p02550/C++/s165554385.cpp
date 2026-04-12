//g++ -std=c++17 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g PROGRAM -o OUTPUT -DLOCAL -lasan -lubsan
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;

typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef vector<pair<int, int>> VPII;
typedef vector<pair<int, PII>> VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;


inline ll modulo(ll a, ll m)
{
    return (a % m + m) % m;
}

inline ll modInverse(ll a, ll m)
{
    assert(__gcd(a, m) == 1);
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

inline ll modPow(ll x, ll y, ll m)
{ //x^y % m
    if (y == 0)
        return 1LL;
    else if (y == 1)
        return x;
    else
    {
        ll ans = modPow(x, y / 2, m) % m;
        if (y & 1)
        {
            return (((ans * ans) % m) * x) % m;
        }
        else
        {
            return (ans * ans) % m;
        }
    }
}

vector<string> split(char d,string s)
{
    stringstream ss(s);
    string t;
    vector<string> words;
    while(getline(ss,t,d))
    {
        words.pb(t);
    }

    return words;
}

int main(int argc, char *argv[])
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, m;
    cin >> n >> x >> m;

    VII ord;
    map<int, int> st;
    while(st.find(x)==st.end()){
        ord.pb(x);
        st[x] = ord.size()-1;
        x = ((x % m) * (x % m)) % m;
    }

    VII cyc,nyc;
    for (int i = 0; i < st[x];++i)
        nyc.pb(ord[i]);

    ll fsum = 0;
    for (int i = st[x]; i < ord.size();++i)
        cyc.pb(ord[i]),fsum+=0LL+ord[i];

    // for(auto x:nyc)
    //     cout << x << ' ';
    // cout << endl;
    // for(auto y:cyc)
    //     cout << y << ' ';
    ll ans = 0;
    int i = 0;
    while(n>0LL && i<nyc.size()){
        ans += nyc[i];
        i++;
        n--;
    }
    if(n>0LL){
        ll cmp = n / ((ll)(cyc.size()));
        ans += (fsum * cmp);
        n = n % ((ll)cyc.size());
        int i = 0;
        while(n>0LL){
            ans += cyc[i++];
            n--;
        }
    }

    cout << ans;
    return 0;
}
