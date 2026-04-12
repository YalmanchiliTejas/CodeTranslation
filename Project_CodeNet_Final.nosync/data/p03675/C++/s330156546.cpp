#include "bits/stdc++.h"
#include <deque>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define mset(a,x) memset(a,x,sizeof(a))
#define OUT(x) cout<<(x)<<"\n"
#define SZ(x) (int)(x).size()
#define FASTIO cin.tie(0),ios::sync_with_stdio(0)



int main() {
    deque<int> q;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) scanf("%d", &a[i]);

    rep(i, n) {
        if(i % 2 == 0) {
            q.push_back(a[i]);
        }
        else {
            q.push_front(a[i]);
        }
    }

    if(n % 2 == 1) reverse(ALL(q));

    rep(i, n) {
        cout << q[i];
        cout << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}