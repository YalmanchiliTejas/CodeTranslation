#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll> > P3;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i,h) cin >> s[i];
    REPR(i,w-1){
        bool f=true;
        REP(j,h)f &= s[j][i]=='.';
        if(f){
            REP(j,h) s[j].erase(s[j].begin()+i);
        }
    }
    REPR(i,h-1){
        bool f=true;
        for(auto j : s[i]) f &= j=='.';
        if(f){
            s.erase(s.begin()+i);
        }
    }
    for(auto i : s){
        cout << i << endl;
    }
    return 0;
}
