#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define fl(i,a,n) for(int i=a; i<=n; i++)
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define test()  int tt;  cin>>tt;  while(tt--)
#define nl  cout<<"\n"
#define pii pair<int,int>
#define sz(v) ((int)(v).size())
#define get(a,st,en)  fl(i,st,en)       cin>>a[i]
#define pr(a,st,en)     fl(i,st,en)     cout<<a[i]<<" \n"[i==en]
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)    {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
const int mod=1e9+7;
const int MAX=3005;
ll dp[MAX][MAX];
void solve()    {
        int n;  cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)    cin>>a[i];
        for(int L=n-1;L>=0;L--) {
                for(int R=L;R<n;R++)    {
                        if(L==R)        dp[L][R]=a[L];
                        else    {
                                dp[L][R]=max(a[L]-dp[L+1][R], a[R]-dp[L][R-1]);
                        }
                }
        }
        cout<<dp[0][n-1];
}
/*  Integer Overflow  */
int main()  {
    fast;
    //test()
        solve();
}