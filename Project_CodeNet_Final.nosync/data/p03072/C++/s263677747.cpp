#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)
#define IN(a, x, b) (a<=x && x<b)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main()
{
    INIT;
    int n;
    cin >> n;
    int count = 0;
    vector<int> h(n);
    REP(i,n){
        cin >> h.at(i);
    }
    for(int i = 1; i < n; i++){
        int ma = h.at(i-1);
        for(int j = 0; j < i; j++){
            ma = max(ma, h.at(j));
            
        }
        if(ma <= h.at(i)) count++;
    }
    cout << count + 1 << endl;
    return 0;
}