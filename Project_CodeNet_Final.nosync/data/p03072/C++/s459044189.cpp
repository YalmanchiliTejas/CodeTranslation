#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
#define clr(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define pb push_back
#define mkp make_pair
#define forn(i, n) for(int i=0; i<(int)n; ++i)
#define forab(i, a, b) for(int i=(int)a; i<(int)b; ++i)

const int inf = (int)1e6+5;
const int nax = (int)3e5+5;

void compute(){
    int n; cin >> n;
    vi v(n);
    int mx = 0, res = 0;
    forn(i, n){
        int x;
        cin >> x;
        if(x >= mx){
            ++res;
        }
        mx = max(x, mx);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //    int t;
    //    cin>>t;
    //    while(t--)
    compute();
    return 0;
}
