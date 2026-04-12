#include <bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define mp make_pair
#define fi first
#define se second

using namespace std;
const int maxn =200009;
int n,x[maxn],y[maxn],cnt[maxn];
pair<int,int> a[maxn*2];
main()
{
    #ifdef abcxyz
    freopen("a.inp", "r", stdin);
    #endif
    cin >> n;
    int mn=1e9,mx=0,mn1=0,mx1=1e9;
    fto(i,1,n){
        cin >> x[i] >> y[i];
        if(x[i]>y[i])swap(x[i],y[i]);
        mn=min(mn,x[i]);
        mn1=max(mn1,x[i]);
        mx=max(mx,y[i]);
        mx1=min(mx1,y[i]);
    }
    int res=(mn1-mn)*(mx-mx1);
    if(n==1){cout << res; return 0;}
    int m=0;
    fto(i,1,n){
        a[++m]=mp(x[i],i);
        a[++m]=mp(y[i],-i);
    }
    sort(a+1,a+m+1);
    if(a[1].se+a[m].se==0){
        if(a[1].fi==a[2].fi)swap(a[1],a[2]);
        else if(a[m].se==a[m-1].se)swap(a[m],a[m-1]);
        else{cout << res; return 0;}
    }
    int j=2;
    int s=0;
    //cout << res <<endl;
    for(int i=2; i<m; ++i){
        while(s<n && j<m){
            int tg=++cnt[abs(a[j].se)];
            if(tg==1)++s;
            ++j;
        }
        if(s==n)res=min(res,(a[m].fi-a[1].fi)*(a[j-1].fi-a[i].fi));
        else break;
        //cout << i <<' '<<s<<' '<< (a[m].fi-a[1].fi)<<' '<<(a[j-1].fi-a[i].fi) <<endl;
        int tg=--cnt[abs(a[i].se)];
        if(tg==0)--s;
    }
    cout << res;
    return 0;
}
