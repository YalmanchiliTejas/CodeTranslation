#include<bits/stdc++.h>
#define ll long long
#define F(type, i, a, b) for(type i = a; i <= b; i ++)
#define RF(type, i, a, b) for(type i = a; i >= b;i --)
#define sz(a) sizeof(a)
#define deb(a) cerr<<" ["<<#a<<"->"<<a<<"] "
#define next_line cerr<<'\n'
#define all(a) a.begin(), a.end()
#define iter(it, s) for(auto it = s.begin(); it != s.end(); it ++)

using namespace std;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve()
{
    //If you cannot approach a problem
    //directly in the way it is proposed then try to think from backwards
    int n;
    cin>>n;
    if(n >= 30){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        freopen("Debug.txt", "w", stderr);
    #else
    #endif
        solve();
}
