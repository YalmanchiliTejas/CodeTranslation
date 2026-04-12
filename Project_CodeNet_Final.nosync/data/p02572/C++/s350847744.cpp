#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#define l(i,a,b) for(auto i=a;i<b;i++)
#define lr(i,a,b) for(auto i=a;i>=b;i--)
#define ll long long
#define lli long long int
#define ld long double
#define vec vector<int>
#define mii map<ll,ll>
#define vl vector<long long>
#define se set <long long int>
#define pi pair<long long,long long>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define in(x) cin>>x
#define o(x) cout<<x
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.14159265359
using namespace std;


ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}

//const string k = "enterstringtobechecked";



int main()
{
    SYNC
    //clock_t tStart = clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n; in(n);
    vl v(n);
    l(i,0,n)
    {
        in(v[i]);
    }
    ll ans=0,sum=0;
    ll MOD = 1e9 + 7;
    l(i,0,n)
    {
        ans+= (ll)(v[i]*sum);
        ans %= MOD;
        sum+= v[i];
        sum %=MOD;
    }
    o(ans)<<endl;








   // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   
}
