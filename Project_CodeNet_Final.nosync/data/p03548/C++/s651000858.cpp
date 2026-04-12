#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e7 + 1;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector <ll> vi;
typedef vector < pair<ll, ll > > vp;
typedef vector <vector<ll>> vv;
typedef vector <string> vs;
typedef vector <char> vc;


ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
//char c;

#define Endl endl


/*--------------------template--------------------*/

int main() {
    cin >> n >> m >> k;

    while (1) {
        if (cnt*m + (cnt + 1) * k == n) {
            cout << cnt << endl;
            return 0;
        } else if (cnt*m + (cnt + 1) * k > n) {
            break;
        } else {
            cnt++;
        }
    }
    while (1) {
        if (cnt*m + (cnt + 1) * k == n) {
            cout << cnt << endl;
            return 0;
        } else if (cnt*m + (cnt + 1) * k < n) {
            cout << cnt << endl;
            return 0;
        } else {
            cnt--;
        }
    }
    
}