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

LL n, dp[max_n][max_n], a[max_n];
bool s[max_n][max_n];

LL f(int l, int r){
    if(r<0 || l >= n || l>r) return 0;
    if(s[l][r])
        return dp[l][r];

    s[l][r] = true;
    return dp[l][r] = max(a[l]-f(l+1,r), a[r]-f(l,r-1));
}

int main() {
    gl(n);
    rep(i,n) gl(a[i]);

    cout << f(0,n-1) << endl;
    return 0;
}