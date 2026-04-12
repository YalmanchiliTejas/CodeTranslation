#include <bits/stdc++.h>
#define int long long
#define P(x) cout << x << endl
#define D(x) P(#x << ": " << x)
#define F(i,n) for (int i=0; i<(int)(n); i++)
#define DEC(i,n) for (int i=(int)(n); --i>=0;)
#define S(s) (int)((s).size())
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,(v))
#define MA(a,v) a = max(a,(v))
#define V vector
#define pb push_back
#define mt make_tuple
using namespace std;
int N=100;

int n;
V<int> a;

bool finished() {
    F(i,n) if (a[i] >= n)
        return false;
    return true;
}

int cnt=0;

void lastSteps() {
    //P("hey");
    while (true) {
        int mai = max_element(ALL(a)) - a.begin();
        //P(mai);
        if (a[mai] < n) break;
        cnt++;
        F(i,n) {
            if (i == mai) a[i] -= n;
            else a[i]++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    F(i,n) {
        int e; cin>>e;
        a.pb(e);
    }
    while (true) {
        int ma = *max_element(ALL(a));
        if (ma < 2*n) {
            lastSteps();
            break;
        }
        V<int> group;
        int masmall=0;
        F(i,n) {
            if (a[i] >= ma-n)
                group.pb(i);
            else
                MA(masmall, a[i]);
        }
        int steps = (ma-masmall)/(n+1);
        F(i,n) {
            if (a[i] >= ma-n)
                a[i] -= (n-S(group)+1)*steps;
            else
                a[i] += S(group)*steps;
        }
        cnt += S(group)*steps;
    }
    printf("%lld\n", cnt);
}