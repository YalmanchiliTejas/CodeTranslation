#include <bits/stdc++.h>
using namespace std;

typedef long double ld;                                   // XD
#define int long long   
#define PB push_back 
#define all(x) (x).begin(),(x).end()
#define ii pair <int,int>
#define mii map <int,int>
#define vi vector<int> 
#define vii vector< ii >
#define F first
#define S second 
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a; i>=b; --i)
#define sz(x) (int)((x).size())
const double pi=2*acos(0.0);
inline void io(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);         
#endif
}

const int mod = 1e18+7;
const int maxn = 2e5+5;

void solve(){
	int x; cin>>x;
    if(x >= 30) cout<<"Yes"; else cout<<"No";
}
signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); //io();
    cout<<setprecision(16);
    
    int tc=1;// cin>>tc; 
    while(tc--){
        solve();cout<<'\n';
    }
    return 0;
}

