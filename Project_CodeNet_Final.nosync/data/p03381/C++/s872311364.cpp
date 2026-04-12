#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
#define x1 xdddddddddddddddddd
#define y1 ydddddddddddddddddd

int n,a[200005],x,y;

pi b[200005];

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i]={a[i],i};
    }
    sort(b+1,b+n+1);
    int x=b[n/2].y,y=b[n/2+1].y;
    for(int i=1;i<=n;i++){
        if(a[i]<=a[x]) cout << a[y] << '\n';
        else cout << a[x] << '\n';
    }
}
