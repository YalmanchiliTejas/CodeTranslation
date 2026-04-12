#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,s,n) for(int i = (s);i<(n);i++)
#define repe(i,s,n) for(int i = (s);i<=(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;

int n,m,cnt=0;
char c;

signed main(){
    cin>>n>>m;
    rep(i,0,n*m){
        cin>>c;
        if(c=='#')cnt++;
    }
    
    
    
    (cnt==n+m-1)?puts("Possible"):puts("Impossible");
    return 0;
}