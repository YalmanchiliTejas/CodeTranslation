#include<bits/stdc++.h>
//#define local
#define forn(a,n) for(int i = a; i < n; i++)
#define mod 1000000007


using namespace std;

typedef long long int ll;
typedef vector<int> vec;
typedef vector<ll> vecl;
typedef unsigned long long int ull;
typedef vector<ull> vecu;


void print(const vecl &a)
{
    forn(0,a.size())
        cout << a[i] << " ";
    cout << "\n";
}
void solve()
{
    int n;
    cin >> n;
    vecl a(n);
    forn(0, n)
        cin >> a[i];
    vecl sum(n);
    sum[n - 1] = a[n-1];
    forn(1, n)
        sum[n - i - 1] = (sum[n - i] + a[n - i - 1]) % mod;
       // print(sum);
    ull ans = 0;
    forn(0, n-1)
    {
        ans %= mod;
        ans += (a[i] * sum[i+1]) % mod;
    }
    ans %= mod;
    cout << ans;
    
}



int main()
{
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
            solve();
}