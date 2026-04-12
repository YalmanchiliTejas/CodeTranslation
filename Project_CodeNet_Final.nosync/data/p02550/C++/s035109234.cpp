#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ins insert
#define vi vector<int>
const int mxN=2e5;


int main()
{
    ll n,x,m;
    cin >> n >> x >> m;
    ll sum=x;
    vector<ll> nums;
    vector<ll> c(m+1,0);
    ll used=0;
    bool iszero=false;
    for(int i=1;i<n;i++)
    {
        x=(x*x)%m;
        sum+=x;
        c[x]++;
        if(x==0)
        {
            iszero=true;
            break;
        }
        if(c[x]==2)
        {
            nums.pb(x);
        }
        if(c[x]==3)
        {
            used=i;
            sum-=x;
            break;
        }
        //cout << x << " " << sum << "\n";
    }  
    if(used!=0&&!iszero)
    {
    ll hsum=0;
    ll numssize=nums.size();
    for(ll i=0;i<numssize;i++)
        hsum+=nums[i];
    n-=used;
    ll multi=n/nums.size();
    sum+=multi*hsum;
    ll remain=n-multi*nums.size();
    for(ll i=0;i<remain;i++)
        sum+=nums[i];
    }
    cout << sum;
}