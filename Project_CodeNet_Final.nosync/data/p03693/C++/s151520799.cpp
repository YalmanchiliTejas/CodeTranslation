#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i,k,n) for(int i = k; i < n; i++)
//#define sum(start, end) accumulate(start, end, 0)
#define mmax(start, end) *max_element(start, end)
#define mmin(start, end) *min_element(start, end)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef string str;

using namespace std;
template <class T = ll> T in() { T _in; cin >> _in; return (_in); }


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll rgb = in()*100 + in()*10 + in();

    if (rgb%4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
