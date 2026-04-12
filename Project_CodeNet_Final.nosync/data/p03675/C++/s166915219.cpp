#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define rd(x) cin >> x;
#define rda(a,n) for(int i=1;i<=n;i++) cin >> a[i];
#define wr(x) cout << x << ' ';
#define wrl(x) cout << x << '\n';
#define wra(a,n) for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << '\n';
#define lg length()
#define pb push_back
ifstream in("ciclueuler.in");
ofstream out("ciclueuler.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005


int n,a[200005];

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n%2){
        for(int i=n;i>=1;i-=2) cout << a[i] << ' ';
        for(int i=2;i<n;i+=2) cout << a[i] << ' ';
    }
    else{
        for(int i=n;i>1;i-=2) cout << a[i] << ' ';
        for(int i=1;i<n;i+=2) cout << a[i] << ' ';
    }
}
