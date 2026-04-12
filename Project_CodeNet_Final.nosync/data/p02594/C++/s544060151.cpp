 /***     
 * When I wrote this
 * only God & I understood
 * what I was doing
 * Now, God only knows 
 /***/ 
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <iomanip>
#include<map>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
//fixed<< setprecision(2)
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll t;
    while (cin >> t)
    {
        if(t>=30)cout<<"Yes\n";
        else cout<<"No\n";
    }
}