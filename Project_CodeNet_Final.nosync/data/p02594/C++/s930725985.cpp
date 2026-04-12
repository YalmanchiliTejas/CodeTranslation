#include <bits/stdc++.h>
using namespace std;

#define deb(x)        cerr << #x << " = " << x << "\n";
#define deb2(x, y)    cerr << #x << " = " << x << ", " << #y << " = " << y << "\n";
#define deb3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n";

#define pb push_back
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define f  first
#define s  second

#define sortall(x) sort(x.begin(), x.end());
#define sz(x) (int)x.size()

typedef long long         ll  ;

typedef vector < ll >     vl  ;
typedef vector < int >    vi  ;

typedef pair < ll, ll >   pl  ;
typedef pair < int, int > pi  ;

typedef vector < pl >     vpl ;
typedef vector < pi >     vpi ;

void solve() {
    ll n, temp;
    cin >> n;

    if (n >= 30)
    	cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//  freopen ("in.txt", "r", stdin);
//  freopen ("err.txt", "w", stderr); 
//  freopen ("out.txt", "w", stdout);

    ll tc = 1;
    //cin >> tc;

    while(tc--) {
        solve();
        cout << '\n';
    }

    return 0;
}