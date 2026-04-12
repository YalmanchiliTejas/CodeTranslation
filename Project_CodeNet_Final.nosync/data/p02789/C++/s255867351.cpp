#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i,n) for(int (i)=(n);(i)>0;(i)--)
#define rrep(i,n,m) for(int (i)=(n);(i)<(m);(i)++)
#define rrepr(i,n,m) for(int (i)=(n);(i)>(m);(i)--)
#define SORT(s) sort((s).begin(),(s).end())
#define SORTR(s,t) sort((s).begin(),(s).end(),greater<t>())

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;

const int INF = 1000000000;
const ll LINF = 1000000000000000000ll;
const double PI = acos(-1.0);
const double EPS = 1e-10;

const ll MOD = 1000000007ll;
const int MAX=510000;

int N,M;
void input()
{
    cin>>N>>M;
    return;
}

void solve()
{
    string ans="Yes";
    if(N>M) ans="No";
    cout<<ans<<endl;
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}