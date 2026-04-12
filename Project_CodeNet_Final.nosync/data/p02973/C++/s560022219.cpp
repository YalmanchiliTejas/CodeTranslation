#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
using ll = long long;
using ull = unsigned long long;

int main(void)
{
    IOS
    int n; cin >> n;
    vector<int> v;
    int a; cin >> a;
    v.emplace_back(a);    
    REP(i,n-1) {
        int x; cin >> x;
        if (v.back() >= x ) {
            v.emplace_back(x);
        } else {
            auto it = lower_bound(RALL(v),x);
            auto d = distance(v.rbegin(),it);
            //cerr << d << endl;
            v[v.size()-d] = x;
        }
    }
    
    cout << v.size() << endl;

    return 0;
}