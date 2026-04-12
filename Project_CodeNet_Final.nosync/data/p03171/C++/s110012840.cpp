#include <bits/stdc++.h>
#define F(i,n) for (int i=1; i<=(int)n; i++)
#define FF(i,n) for (int i=0; i<(int)n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pi pair < int , int >
#define re(x) (int)x.size()
#define y1 u228
using namespace std;
typedef long long ll;
const int N = 3020;
const int big = 2e9;
const int md = 1e9 + 7;
int n;
ll f[N][N][2],a[N];
bool mrk[N][N][2];
ll go(int l,int r,int x){
    if (l>r) return 0;
    if (mrk[l][r][x]) return f[l][r][x];
    ll tex=0ll; mrk[l][r][x]=1;
    if (x==0) tex=max(a[l]+go(l+1,r,x^1),a[r]+go(l,r-1,x^1));
        else tex=min(-a[l]+go(l+1,r,x^1),-a[r]+go(l,r-1,x^1));
    f[l][r][x]=tex;
    return tex;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>n;
    F(i,n) cin>>a[i];
    cout<<go(1,n,0)<<endl;
    return 0;
}





