#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,n) for(int i=1;i<=(int)(n);i++)
#define rep3(i,n) for(int i=0;i<=(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define repll(i,n) for(ll i=0;i<(ll)(n);i++)
#define repll2(i,n) for(ll i=1;i<=(ll)(n);i++)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define INF (int)1e9  //
#define LINF (ll)4e18  //
#define MOD (int)(1e9)+7
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define yes(n) cout << ((n) ? "yes" : "no"  ) << endl
#define PI 3.1415926535898

//------------------------------------------------------

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    string s = a + b + c;
    YES(stoi(s) % 4 == 0);
    return 0;
}

