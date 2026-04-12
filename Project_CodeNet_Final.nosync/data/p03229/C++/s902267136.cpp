/*
    ##############################
    #  Author: Pratyush Gaurav   #
    #  College: NIT ROURKELA     #
    ##############################
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli > plli;
typedef vector<lli> vlli;
typedef vector<plli > vplli;

#define scan(n) scanf("%lld",&n)
#define scan2(a,b) scanf("%lld %lld",&a,&b)
#define scan3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define print(n) printf("%lld\n",n)
#define scanS(s) scanf("%s",&s)
#define printS(s) printf("%s",s)

#define ff first
#define ss second
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define repr(i,a) for(i = a ; i >= 0 ; i--)
#define REP(i,a,b) for(i = a ; i <= b ; i++)
#define REPR(i,a,b) for(i = a ; i >= b ; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define opt ios_base::sync_with_stdio(false);
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define sqr(x) (x)*(x)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define UN(v) sort(all(v)), v.resize(unique(all(v))-v.begin())

#define endl '\n'

const long long INF = 100000000000000000;
const long long MOD = 1000000007;
const long long MAXN = 100005;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

void solve() {
    lli n;
    cin >> n;
    vlli v(n);
    lli i, j;
    rep (i, n) {
        cin >> v[i];
    }
    sort(all(v));
    i = 1, j = n - 2;
    deque<lli> q;
    lli sum = 0;
    q.push_front(v[n - 1]);
    sum += (q.front() - q.back());
    if(n > 1)   q.push_front(v[0]);
    while (i <= j) {
        lli ele1 = q.front(), ele2 = q.back();
        lli a = abs(v[i] - ele1);
        lli b = abs(v[i] - ele2);
        lli c = abs(v[j] - ele1);
        lli d = abs(v[j] - ele2);
        lli maxi = max(a, max(b, max(c, d)));
        if (maxi == a) {
            q.push_front(v[i]);
            i++;
        } else if (maxi == b) {
            q.push_back(v[i]);
            i++;
        } else if (maxi == c) {
            q.push_front(v[j]);
            j--;
        } else {
            q.push_back(v[j]);
            j--;
        }
    }
    //if (abs(v[i] - q.front()) > abs(v[i]))
    for(i = 1; i < q.size(); i++) {
        sum += abs(q[i] - q[i - 1]);
    }
    cout << sum << endl;
}

int main()
{
    opt;
    lli t = 1;
    //cin >> t;

    while(t--)
        solve();
    return 0;
}