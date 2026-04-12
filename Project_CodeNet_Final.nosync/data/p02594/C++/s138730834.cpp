#pragma GCC optimize("Ofast")
//#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<set>
#include<iterator>
#include<string>
#include<map>
#include<stack>
#include<cmath>
#include<algorithm>
#include <cstdio>
#include<cstdlib>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include<numeric>
#define baap_coder17 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define   lli long long int
#define ld long double
#define  endl "\n"
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ui unsigned int
#define mt make_tuple
#define t_(t)[(i)]  get<(i)>((t))
#define vsort(v) sort((v).begin(), (v).end())
#define vsortr(v) sort((v).rbegin(), (v).rend())
#define all(v)  (v).begin(), (v).end()
#define rall(v)  (v).rbegin(), (v).rend()
#define vdp(n,x) vector<vector<ll>>dp(n+1,vector<ll>(x+1));
const ld EPSILON=0.000000001;
const ld mod=1e9+7;
const lli AM=2e5+5;
const ld pi=3.14159265358979323846;
lli max(lli a,lli b){if(a>b)return a;else return b;}
using namespace std;
lli fact(lli n) {lli ans=1; for(lli i=1;i<=n;i++) ans*=i; return ans;}
lli powm(lli a, lli b, lli n){lli x=1, y=a; while (b > 0) {if (b%2 == 1) {x = (x*y) % n; } y = (y*y) % n; b /= 2;}return x % n;}
lli pow(lli x, lli y) { lli res = 1; while (y > 0) { if (y & 1) res = ((res) * (x)); y = y >> 1; x = ((x) * (x)); } return res; }
lli min(lli a,lli b) {if(a>b)return b;else return a;}
bool cmp(ld x,ld y){if(abs(x-y)<=EPSILON)return 1;return 0;}
 bool checkprime(lli n){ for(lli i=2;i*i<=n;i++) if(n%i==0)return false;   return true;}
//lli gcd(lli a, lli b){return b ? gcd (b, a % b) : a;}
 int fun(pair<lli,lli> p1,pair<lli,lli> p2)
{
    if(p1.X<=p2.X)
        return 1;
    return 0;
}
//lli lcm(lli a, lli b) { return (a * b) / gcd(a, b); }
//lli modInverse(lli a, lli m) { lli g = gcd(a, m); return powm(a, m - 2, m); }

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}





int main()
{
    int x;cin>>x;
    if(x>=30)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
