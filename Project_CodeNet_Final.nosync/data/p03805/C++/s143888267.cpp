#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using mii = map<int, int>;
const int INF = 1e9;
const ll LINF = 1e18;
#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define ALL(x) (x).begin(),(x).end()
#define IN(type,a) type a;cin >> a
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define COUT(x) cout << (x) << endl
#define DCOUT(x,n) cout << fixed << setprecision(n) << (x) << endl
int gcd(int x, int y){
    if ((x==1)||(y==1)) {
        return 1;
    }
    if (x>y) {
        if (x%y==0) {
            return y;
        }else{
            return gcd(y, x%y);
        }
    }else{
        if (y%x==0) {
            return x;
        }else{
            return gcd(x, y%x);
        }
    }
}
int main() {
    IN(int, n);
    IN(int, m);
    vector<vector<bool>> a(n,vector<bool>(n,false));
    REP(i, m){
        IN(int, k);
        IN(int, l);
        a[k-1][l-1] = true;
        a[l-1][k-1] = true;
    }
    vector<int> li;
    REP(i, n){
        li.push_back(i);
    }
    int ans = 0;
    do {
        if (li[0]!=0) {
            break;
        }
        cout << endl;
        bool flag = true;
        REPS(i, n-1){
            if (!a[li[i-1]][li[i]]) {
                flag = false;
            }
        }
        if (flag) {
            ans ++;
        }
    } while (next_permutation(ALL(li)));
    COUT(ans);
}


