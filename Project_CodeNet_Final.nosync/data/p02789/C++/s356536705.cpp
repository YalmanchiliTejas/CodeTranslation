#include <bits/stdc++.h>
#include <ctime>
#include <sstream>
#define weewoo ios::sync_with_stdio(false);cin.tie(0)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
#define ll long long
#define se second
#define fi first
#define ctoi(x) x-'0'
#define pi (acos(-1))
#define llputin(a,n) for(int i=0;i<n;i++){ll x;cin >> x;a.push_back(x);}
#define iputin(a,n) for(int i=0;i<n;i++){int x;cin >> x;a.push_back(x);}

#define MOD ((ll) 1e9 + (ll) 7)
using namespace std;

ll pw(ll x,ll a){
    if(a==0)
        return 1;
    ll t = pw(x,a/2);
    if(a%2==0)
        return (t*t);
    else
        return (t*t*x);
}

bool prime(int x)
{
    if(x < 2) return false;
        for(int i=2; i<= sqrt(x); i++) {
            if ((x%i) == 0) return false;
        }
    return true;
}

ll d[200100];
vector<pll>a;
int main()
{
    weewoo;
    ll n,m;
    cin >> n >> m;
    if(n==m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
