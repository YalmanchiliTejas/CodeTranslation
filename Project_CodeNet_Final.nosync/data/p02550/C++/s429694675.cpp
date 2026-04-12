#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    constexpr int MOD = 1e5;
    IOS
    ll N; cin >> N;
    ll X,M; cin >> X >> M;
    vector<int> loop(MOD);
    vector<int> f(1);
    int count = 1;
    while(loop[X] == 0 && X != 0 && count <= N) {
        // cerr << X << endl;
        loop[X] = count;
        count++;
        f.push_back(X);
        X *= X;
        X %= M;
    }
    if (X == 0 || loop[X] == 0) OUT(accumulate(ALL(f),0LL))
    else {
        // cerr << X << endl;
        ll loopsize = count - loop[X];
        ll lcount = (N-loop[X]+1) / loopsize;
        ll lmod = (N-loop[X]+1) % loopsize;
        // cerr << loopsize << " " << lcount << " " << lmod << endl;
        ll loopsum = 0;
        REP(i,loopsize) loopsum += f[loop[X]+i];
        ll ans = 0;
        FOR(i,1,loop[X]) ans += f[i];
        ans += loopsum * lcount;
        REP(i,lmod) ans += f[loop[X]+i];
        OUT(ans)
    }




    return 0;
}