/******************************************
* AUTHOR : AMAN SAXENA *
* Nick : blue-meth *
* "There's some good in this world, and it's worth fighting for." *
* INSTITUTION : KIET Group of Institutions *
******************************************/
#include <bits/stdc++.h>

const long long MODULO=1000000007;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define FOR1(i,a,n) for(int i=a;i<=n;i++)
#define FOR2(i,a,n) for(int i=a;i>=n;i--)
#define pb push_back
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pi 3.14159265359

using namespace std;

ll amanpower(ll a, ll b) {
    ll r = 1;
    while (b > 0) 
    {
        if (b & 1) r = r * a;
        a = a * a;
        b >>= 1;
    }
    return r;
}


ll amanlcm(ll a, ll b)
{
     return a*(b/__gcd(a,b));
}


//********* CODE START *********

void solve()
{
    int n;
  	cin >> n;
  	cout << ((n >= 30)? "Yes":"No");
}

void test()
{
    int t;
    cin>>t;
    while(t--) //for(int j=1;j<=t;j++) cout << "Case #" << j << ": ";
    {
        solve();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    
    // test();
    solve();

    
    return 0;
}