#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(long long i=s;i<n;i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const double pi = acos(-1.0);
const ll mod = pow(10,9) + 7;
const ll INF = pow(2,31) - 1;

ll gcd(ll x,ll y)
{
    ll r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

ll lcm(ll x,ll y)
{
    x /= gcd(x,y);
    y /= gcd(x,y);
    return (x*y);
}

int main()
{
    string s;
    cin >> s;
    rep(i,2)if(s[i] != s[i+1]){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}