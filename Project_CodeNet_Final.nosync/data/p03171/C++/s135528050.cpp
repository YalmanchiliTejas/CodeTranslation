#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define endl '\n'
#define sz(x) (int) x.size()
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
const int maxn=3e3+5;
int64 f[maxn][maxn];
int64 a[maxn];
int n;
void Input()
{
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        a[i]+=a[i-1];
    }
}
int64 calc(int l, int r)
{
    if (l==r) return a[l]-a[l-1];
    int64 &res=f[l][r];
    if (res!=f[0][0]) return res;
    return res=a[r]-a[l-1]-min(calc(l+1,r),calc(l,r-1));
}
void Solve()
{
    fillchar(f,sizeof(f),63);
    cout << calc(1,n)*2-a[n] << endl;
}
int main()
{
    #ifdef meomeomeooooo
        freopen("input.txt","r",stdin);
        //freopen(".out","w",stdout);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}

