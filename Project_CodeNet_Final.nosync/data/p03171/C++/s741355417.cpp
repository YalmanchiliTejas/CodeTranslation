#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define vi vector<int>
#define vll vector<long long>
#define ll long long
#define ull unsigned long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define nl cout<<'\n'
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pll pair<long long,long long>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define si set<int>
#define sll set<long long>
#define all(v) (v).begin(),(v).end()
#define Unique(x)           (x).erase(unique(all(x)), x.end())
#define v_present(vec,x)  (find(all(vec),x)!=(vec).end())
#define present(myset,x)    ((myset).find(x)!=(myset).end())
#define Cprint(c)  for(auto i:(c)) { cout<<i<<" "; } nl
#define trace2(x,y) cout<<x<<" "<<y<<endl;
#define trace3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define trace4(x,y,z,a) cout<<x<<" "<<y<<" "<<z<<" "<<a<<endl;
ll mod = 1e9+7;
const int MAX = 1e5+5;

using namespace std;

int n;
vll a(3005);
ll dp[3005][3005];


ll solve(int i, int j){
    if(!((i>=0 && i<n) &&(j>=0 && j<n) && i<=j))
    {
        return -1e15;
    }
    if(i==j){
        dp[i][j]=a[i];
        return a[i];
    }

    if(j==i+1){
        dp[i][j]=max(a[i],a[j])-min(a[i],a[j]);
        return dp[i][j];
    }

    ll &ans=dp[i][j];
    if(ans!=-1)
        return ans;

    ll x=0; ll y=0;
    ll ans1=1e15; ll ans2=1e15;
    if(i<n){
        x=a[i];
        if(i+1<n){
            y=a[i+1];
            //cout<<"1";
            ll diff = solve(i+2,j);
            //cout<<diff<<" "<<x<<" "<<y;nl;
            ans1=min(ans1,diff+x-y);
        }

        if(j>=0){
            y=a[j];
            //cout<<"2";
            ll diff = solve(i+1,j-1);
            //cout<<diff<<" "<<x<<" "<<y;nl;
            ans1=min(ans1,diff+x-y);
        }
    }

    if(j>=0){
        x=a[j];
        if(i<n){
            y=a[i];
            ll diff = solve(i+1,j-1);
            //cout<<diff<<" "<<x<<" "<<y;nl;
            ans2=min(ans2,diff+x-y);
        }

        if(j-1>=0){
            y=a[j-1];
            //cout<<'4';
            ll diff = solve(i,j-2);
            //cout<<diff<<" "<<x<<" "<<y;nl;
            ans2=min(ans2,diff+x-y);
        }
    }
    ans=max(ans1,ans2);
    //cout<<i<<" "<<j<<" "<<ans;nl;
    //cout<<"///";nl;

    return ans;


}


int main()
{
    FAST_IO;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    ll ans=solve(0,n-1);
    cout<<ans;
    return 0;

}