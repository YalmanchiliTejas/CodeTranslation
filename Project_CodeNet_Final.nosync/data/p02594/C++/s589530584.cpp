#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define MOD 1000000007
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
typedef long long ll;
typedef long double ld;
const int MAX = 2e5 + 5;
const int MAXN = 105;

// vector<ll> primes;
// void seive() {
//     vector<int> v(MAX);
//     for (int i = 2; i * i < MAX; i++) {
//         if (v[i] == 0) {
//             for (int j = i * i; j < MAX; j += i) v[j] = 1;
//         }
//     }
//     primes.pb(2);
//     for (int i = 3; i < MAX; i += 2) if (v[i] == 0) primes.pb(i);
// }
// ll pw(ll a, ll n) {
//     ll rs = 1;
//     while (n) {
//         if (n & 1) rs = rs * a;
//         n >>= 1;
//         a = a * a;
//     }
//     return rs;
// }
// bool isPrime(ll n) {
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }
vector<int> a(MAX),b(MAX);
vector<int> g[MAX];
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for printing output from output.txt
    freopen("output1.txt", "w", stdout);
#endif
    // int t;
    // cin >> t;
    // while (t--) {
    // }
    int x;
    cin>>x;
    if(x>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}

