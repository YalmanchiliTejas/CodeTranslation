#include<bits/stdc++.h>
#define ls(x) (x)<<1
#define rs(x) (x)<<1|1
#define fu(i,r,t) for(int i=r;i<=t;i++)
#define fd(i,r,t) for(int i=r;i>=t;i--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define lcm(a,b) (a*b)/__gcd(a,b)
#define Case(i,ans) cout<<"Case "<<i<<": "<<ans<<endl;
#define cp(i,ans) printf("%.if",ans);
#define cpp(i,ans) cout<<setprecision(i)<<fixed<<ans<<endl;
#define ppb pop_back
#define ppf pop_front
#define pb push_back
#define pf push_front
#define pq priority_queue
#define lowbit(x) (x)&(-x)
#define all(V) V.begin(),V.end()
#define ms multiset
#define mod(x) (x)%mo_num
#define vc vector
#define vct vector<int>
#define fa(i,V) for(auto i:V)
#define out(i) cout<<i<<endl;
#define fi first
#define sc second
#define fun(i) fu(i,1,n)
#define fut(i) fu(i,1,t)
#define fum(i) fu(i,1,m)
//#define P pair<int,int>
using namespace std;
const int INF=1e17+5;
const int maxn=2e5+5;
const int mo_num=1e9+7;
int n,m,a[maxn],b[maxn],ans;
bool cmp(int a,int b)
{
    return a>=b;
}
int weihu1[maxn],weihu2[maxn],last=0,Last=0;
int32_t main()
{
    IOS
    cin>>n;
    weihu1[last]=-1;
    fun(i)
    {
        cin>>a[i];
        //最长不上升子序列
        a[i]<=weihu1[last]?weihu1[++last]=a[i]:weihu1[lower_bound(weihu1,weihu1+last+1,a[i],cmp)-weihu1]=a[i];
        //最长上升子序列
//        a[i]>weihu2[Last]?weihu2[++Last]=a[i]:weihu2[lower_bound(weihu2,weihu2+Last+1,a[i])-weihu2]=a[i];
    }
    out(last+1)
    return 0;
}
