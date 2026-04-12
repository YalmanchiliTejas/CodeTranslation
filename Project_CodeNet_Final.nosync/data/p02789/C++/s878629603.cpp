#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(ll i=a; i<b; i++)
#define rloop(i,a,b) for(ll i=a; i>b; i--)
#define all(var) var.begin(), var.end()
#define eloop(var) for(auto elem : var)
#define debug(x) cerr<<#x<<" ----> "<<x<<endl;
#define PB push_back
#define MP make_pair
#define tt ll TT; cin>>TT; while(TT--)
#define F first
#define S second
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define INF 0x7fffffff
#define LINF 2000000000000000007
#define MOD 1000000007
#define MAX 100005
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //tt
    {
        ll n,m;
        cin>>n>>m;
        if(n==m)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}