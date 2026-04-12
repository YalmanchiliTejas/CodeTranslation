#include <bits/stdc++.h>
using namespace std;

#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)

#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)

#define wez(n) int (n); cin >> n
#define wez2(n,m) int (n),(m); cin >> n >> m
#define wez3(n,m,k) int (n),(m),(k); cin >> n >> m >> k

#define whileZ int T; cin >> T; while(T--)

#define ALL(c) (c).begin(),(c).end()
#define ll long long 
#define ull unsigned long long
#define ld long double

#define fi first
#define se second

// for debug
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) if(a.size()) printA(a,0,a.size()-1)

#define pb push_back
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;
//  priority_queue <int, vector<int>, greater<int> > pq; // min heap

ll a[200005];
ll pre[200005];
const ll m = 1000000007LL;
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    wez(n);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pre[i] = (pre[i-1] + a[i]) % m;
    }
    for (int i=1; i<=n; i++) 
        ans = ( ans + a[i]*pre[i-1] ) % m;

    cout << ans << '\n';    
    return 0;
}