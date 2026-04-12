#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int main(){
#ifdef LOCAL_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int a, b, c, d;
    int n, m;
    string s;
    vi v;
    vector<string> vs;

    string yes = "Yes", no = "No";
    cin >> s;
    bool f = false;
    REP(i, 1, s.size()) if(s[i] == 'C' && s[i-1] == 'A') f = true;
    cout << (f ? yes : no) << endl;

    return 0;
}