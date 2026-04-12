#include<bits/stdc++.h>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<llint, llint> pll;
typedef vector<int> vi;
typedef vector<llint> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define ci cin
#define co cout
#define en endl
#define ln cout<< '\n'
#define rep(i, n) for(int i = 0; i < n; i++)
#define outl(x) cout<< (x) << '\n'
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

template<typename Tn> Tn gcd(Tn a, Tn b)
{
    return (b ? gcd(b, a % b) : a);
}

template<typename Tn> Tn lcm(Tn a, Tn b)
{
    return a / gcd(a, b) * b;
}

string IntToString(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

llint cnt = 0;

int main()
{
    int n;
    int h;
    int mx = 0;
    
    ci >> n;
    rep(i, n) {
	ci >> h;
	mx = max(mx, h);
	if(mx <= h) cnt++;
    }

    co << cnt << en;
    
    return 0;
}
