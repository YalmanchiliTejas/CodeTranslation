#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

constexpr size_t N = 55;
ll p[N];
ll b[N];

void precalc(int n) {
    p[0] = 1;
    b[0] = 1;
    FOR(i,1,n) {
        p[i] = p[i-1] * 2 + 1;
        b[i] = b[i-1] * 2 + 3;
    }
}

ll countputty(ll lev,ll &layer) {
    //cerr << lev << " " << layer << endl;
    ll ret = 0;
    if (lev == 0) {
        layer--;
        return 1;
    } else {
        layer--;
        if (layer >= b[lev-1]) {
            ret = p[lev-1];
            layer -= b[lev-1];
        } else if (layer > 0){
            ret = countputty(lev-1,layer);
        }
        //cerr << "c " << lev << " " << layer << endl;
        if (layer > 0) {
            ret++;
            layer--;
        }
        if (layer >= b[lev-1]) {
            ret += p[lev-1];
            layer -= b[lev-1];
        } else if (layer > 0) {
            ret += countputty(lev-1,layer);
        }
    } 
    return ret;
}

int main(void)
{
    IOS
    ll n,x;
    cin >> n >> x;
    precalc(n);

    cout << countputty(n,x) << endl;


    return 0;
}