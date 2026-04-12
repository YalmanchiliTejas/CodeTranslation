#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define endl "\n"
#define float long double
#define int long long int
#define f(i, a, b) for(int i=a; i<b; i++)
#define fb(i, a, b) for(int i=a; i>=b; i--)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define LB lower_bound
#define UB upper_bound
#define g(t, n) get<n>(t)
#define fp(x, y) fixed<<setprecision(y)<<x
#define PI 3.141592653589793238462643383279502884
using namespace std;

const int M = (int)2e5+5;
const int mod = (int)1e9+7;

void solve()
{
    int n;
    cin>>n;
    cout<<((n >= 30) ? "Yes" : "No");
}

int32_t main()
{
    IOS
    int t = 1;
    // cin>>t;
    f(tno, 1, t+1)
    {
        // cout<<"Case #"<<tno<<": ";
        solve();
    }
    return 0;
}