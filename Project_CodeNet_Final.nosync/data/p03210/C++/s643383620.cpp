#include <bits/stdc++.h>

#define int         long long
#define uint        unsigned int
#define ld          long double
#define showoff     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define pii         pair<int,int>
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define f           first
#define se          second
#define maxn        200005
#define all(v)      v.begin(),v.end()
#define endl        "\n"
#define sz(x)       (int)x.size()
#define mod         1000000007
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue< int,vi ,greater< int >>
#define INF         1e18

using namespace std;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


signed main()
{
    showoff;
    int n;
    cin >> n;
    /*int fa = 0;
    for(int i=2;i*i <= n;++i)
    if(n%i == 0)fa = i;
    if(fa == 0){cout << "NO\n";return 0;}
    cout << "YES\n";
    */
    if(n == 7 || n == 5 || n == 3)cout << "YES";
    else cout << "NO";
    return 0;
}
