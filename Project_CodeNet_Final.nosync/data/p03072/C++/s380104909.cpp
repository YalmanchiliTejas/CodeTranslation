#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 100000000000
#define eps 1e-7
#define mod 1000000007
#define itn int
#define int ll
using namespace std;

int N;
int H[25];

signed main(void) {
    cin>>N;
    rep(i, N) {
        cin>>H[i];
    }
    int ans=1;
    Rep(i,1,N) {
        bool ok=true;
        Rep(j,0,i) {
            if (H[i]<H[j]) ok=false;
        }
        if (ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}