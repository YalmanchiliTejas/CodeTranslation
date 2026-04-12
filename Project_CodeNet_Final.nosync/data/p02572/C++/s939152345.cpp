#include <bits/stdc++.h>
using namespace std;
 
/*** Template Begins ***/
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
 
// Debug //
 
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

/*** Template Ends ***/
#define int long long
int modexpo(int x,int y)
{
    x %= hell;
    int res = 1;
    while(y){
        if(y&1) res = (res*x)%hell;
        x = (x*x)%hell;
        y = y/2;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    int sum=0,sq=0,ans=0,a;
    rep(i,0,n){
        cin>>a;
        sq=(sq+(a*a)%hell)%hell;
        sum=(sum+a)%hell;
    }
    ans=(sum*sum%hell - sq + hell)%hell;
    ans=(ans * modexpo(2,hell-2))%hell;
    cout<<ans<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}