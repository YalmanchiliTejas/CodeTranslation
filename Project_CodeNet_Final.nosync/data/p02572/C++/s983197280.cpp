using namespace std;
#include <bits/stdc++.h>
#define frr(i, r, l) for(int i = r; i >= l; --i)
#define fr(i, l, r) for(int i = l; i < r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define MEMS(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define m_p make_pair
#define pb push_back
#define ll long long
#define ld long double
typedef pair<ll, ll> iPair; 
priority_queue< ll, vector <ll> , greater<ll>>pq1,pq2;
#define maxN 1000000000000000000
ll power(ll a,ll b){ll res=1;while(b>0){res*=a;b--;}return res;}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,sum=0,pref[200005],ar[200005],mod=1000000007;
    cin>>n;
    pref[0]=0;
    fr(i,0,n)
    {
        cin>>ar[i];
        sum+=ar[i];
        pref[i]=sum;
    }
    ll ans=0;
    frr(i,n-1,1)
    {
        ll st=pref[i-1]%mod;
        ll st1=(ar[i]*st)%mod;

        ans=(ans+st1)%mod;
    }
    cout<<ans<<endl;
    return 0;
}