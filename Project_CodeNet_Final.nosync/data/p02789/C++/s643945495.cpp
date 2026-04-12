#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define mod 1000000007
#define all(x) (x).begin(), (x).end()

const long double PI = acos(-1);
 
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}

int main(){
    ll n, m;
    cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}