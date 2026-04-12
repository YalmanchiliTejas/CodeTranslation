#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll int,ll int>
#define pb push_back
#define sbit __builtin_popcount
#define vec vector <int>
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define bg begin()
#define en end()
#define endl "\n"
#define ff first
#define ss second
#define all(x) x.bg,x.en
#define sz(a) (int)a.size()
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define sp(x) setprecision(x)
#define fill(a,b) memset(a,b,sizeof(a))
#define fr(i,n) for(int i=0;i<n;i++)
#define rp(i,a,b) for(int i=a;i<b;i++)
#define rr(i,a,b) for(int i=a;i>=b;i--)
#define ft(it,x) for(auto it : x)
#define dbg(x) cerr<<#x<<" "<<x<<endl;
#define dbga(arr,n) cerr<<#arr<<": "; rep(tt,0,n)cerr<<arr[tt]<<" "; cerr<<endl;
#define mapi map<int,int>
#define mapl map<ll int,ll int>
#define val_at(x) find_by_order(x)
#define idx_of(x) order_of_key(x)
#define scni(x) scanf("%d",&x)
#define prt(x) printf("%d\n",x)
#define test(t) int t;cin>>t;while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define val_at(x) find_by_order(x)
#define idx_of(x) order_of_key(x)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> myset;
const int mod=1e9+7;
const int mex=1e6+1;
inline ll power(ll a,ll b)
{
    ll ans=1,temp=a;
    while(b!=0)
    {
        if(b&1)
        ans=ans*temp;
        ans=ans%mod;
        temp=temp*temp;
        temp=temp%mod;
        b/=2;
    }
    return ans;
}
int pr[mex];
vec prime;
inline void seive()
{
    rp(i,2,mex) pr[i]=1;
    for(int i=2;i*i<mex;i++)
    {
        if(pr[i])
        for(int j=i*i;j<mex;j+=i)
        pr[j]=0;
    }
    vec prime;
    rp(i,2,mex)
    {
        if(pr[i]) prime.pb(i);
    }
}
ll int xx,xy,d1;
void exeu(ll int a1,ll int b1)
{
    if(b1==0)
    {
        xx=1;
        xy=0;
        d1=a1;
    }
    else
    {
        exeu(b1,a1%b1);
        ll int temp=xx;
        xx=xy;
        xy=temp-(a1/b1)*xy;
    }
}
ll int modinv(ll int A,ll int M)
{
    exeu(A,M);
    return (xx%M+M)%M;
}
int main()
{
    fast
    int m,n;
    cin>>m>>n;
    if(m==n) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}