#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << '\n'
#define SORT(V) sort((V).begin(),(V).end())
#define HSORT(V,n) sort(V,V+n)
#define RSORT(V) sort((V).rbegin(), (V).rend())
#define INF 1e+9
#define MININF -INF
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int x;
    cin >> x;
    if (x == 3||x == 5||x == 7) PRINT("YES");
    else PRINT("NO");
}
