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
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll s[55];
ll p[55];

ll answer(ll num, ll level)
{
    if(level == 1)
    {
        if (2<=num && num <=4)
        {
            return num-1;
        }else if (num<=1)
        {
            return 0;
        }else
        {
            return 3;
        }
        
    }
    if(num < s[level-1]+2)
    {
        return answer(num-1, level-1);
    }else if (num ==s[level-1]+2)
    {
        return p[level-1]+1;
    }else
    {
        return answer(num-2-s[level-1], level-1)+1+p[level-1];
    }
}
int main()
{
    ll n;cin >> n;
    ll x;cin >> x;
    rep(i,n)
    {
        if(i==0)
        {
            s[i] = 1;
            p[i] = 1;
            continue;
        }
        s[i] = 2 * s[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }
    cout << answer(x,n) << endl;

}