#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)
    {
        cin >> a[i];
    }
    deque<int> d;
    rep(i,n)
    {
        auto p = lower_bound(d.begin(), d.end(), a[i])-d.begin();
        if (p==0)
        {
            d.push_front(a[i]);
        }else
        {
            d[p-1] = a[i];
        }        
    }
    int ans = d.size();
    cout << ans << endl;
}