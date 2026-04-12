/* created by <xrssa> */
#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define mod             1000000007
#define all(a)           a.begin(),a.end()
// for lightoj cin cout #define CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif



void solve(){

    int n,m;cin>>n>>m;
    if(n==m) cout << "Yes\n"; else cout << "No";


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
