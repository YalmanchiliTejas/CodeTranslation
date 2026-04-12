//
// Created on 2019-02-09.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }

#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

#define PB push_back
#define INF 1e9
#define MOD 1e9+7
#define EPS 1e-9

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);


    int n, t;
    cin >> n;

    int ans = 0;
    vi before;
    bool isOk = true;
    REP(i, n){
        isOk = true;
        cin >> t;
        for (int h: before){
            if (h > t) isOk = false;
        }
        if (isOk) ans++;
        before.emplace_back(t);
    }

    cout << ans << endl;


    return 0;
}