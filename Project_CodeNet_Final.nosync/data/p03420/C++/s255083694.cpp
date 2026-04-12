#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>=0;i--)
#define I(n) scanf("%d", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#include <bits/stdc++.h>
using namespace std;

//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;

ll n,k;

int main(){
    cin >> n >> k;
    ll ret = 0;
    FOR(b,k+1,n+1){
        ret += (b-k)*(n/b);
        ll a = b*(n/b)+k;
        FOR(ai,a,n+1){
            ret++;
        }
        if (k == 0) ret--;
    }
    cout << ret << endl;
}
