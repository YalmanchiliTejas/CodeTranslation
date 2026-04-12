#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define D(x) cout << #x << " : " << x << endl

#define fs first
#define sc second

#define pb push_back
#define mp make_pair

const int inf=numeric_limits<int>::max();
const LL linf=numeric_limits<LL>::max();

const int max_n=3010;

LL n, dp[max_n][max_n][2], a[max_n];
bool s[max_n][max_n][2];

LL mx(LL aa, LL a, LL bb, LL b, LL c){
    return (c==0)?max(aa+a,bb+b):min(a-aa,b-bb);
}

LL f(int l, int r, int c){
    // D(l<<r<<c);
    if(r<0 || l >= n || l>r) return 0;
    if(s[l][r][c])
        return dp[l][r][c];

    s[l][r][c] = true;
    return dp[l][r][c] = mx(a[l],f(l+1,r,!c), a[r],f(l,r-1,!c), c);
}

int main() {
    gl(n);
    rep(i,n) gl(a[i]);

    cout << f(0,n-1,0) << endl;
    return 0;
}