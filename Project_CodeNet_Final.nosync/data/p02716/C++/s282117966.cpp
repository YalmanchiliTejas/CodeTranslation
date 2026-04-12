#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define vll vector<ll>
#define pll pair<ll , ll>
#define vpll vector<pair<ll, ll> >
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

ll fn(ll x,ll rn[])
{
    if(rn[x]==x) return x;
    else return rn[x]=fn(rn[x],rn);
}

void un(ll x,ll y,ll rn[],ll sz[])
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;
    return;
}

ll power(ll x,ll y)
{
    ll res = 1; // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x)%HOLE;

        // n must be even now
        y = y >> 1; // y = y/2
        x = (x * x)%HOLE; // Change x to x^2
    }
    return res;
}

vector <ll> adjl[N];
ll marked[N]={0};
vector <ll> order;

void dfs (ll x){

    if(marked[x])
        return;
    marked[x]=1;

    REP(i,0,adjl[x].size()){

    }

    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q=1;
    //cin>>q;
    while(q--){

        int flag=0;

        ll n;
        cin>>n;

        ll a[n];

        REP(i,0,n){
            cin>>a[i];
        }


        ll dp[n+1][2];
        dp[0][0]=0;
        dp[1][1]=a[0];
        dp[1][0]=0;

        REP(i,2,n+1){
            if(i%2){

                dp[i][0]=max(dp[i-2][0]+a[i-1],dp[i-1][0]);
                dp[i][1]=dp[i-2][1]+a[i-1];
            }
            else{
                dp[i][0]=max(dp[i-2][0]+a[i-1],dp[i-1][1]);
            }
        }

        cout<<dp[n][0]<<endl;


    }

return 0;
}
