#include<bits/stdc++.h>
#define ll long long
#define dl double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define mod 1000000007
#define P(a,b) pair<a,b>
#define CIN(V,s,n) for(int i=s;i<n;i++){cin >> V[i];}
#define COUT(V,s,n) for(int i=s;i<n;i++){cout <<  V[i] << " ";}

using namespace std;
bool sortBylen(string &a,string &b)
{
    if(a.size()>b.size())
        return true;
    else if(a.size()==b.size())
    {
        if(a>b)
        {
            return true;
        }
        else
            false;
    }
    else
        return false;
}

vector<vector<ll> > DP(3e3+1,vector<ll> (3e3+1,-1));

ll GT(vector<ll> &V,ll s,ll e,ll &n)
{
    if(s>e)
        return 0;
    if(s==e-1)
        return max(V[s],V[e]);
    if(s==e)
        return V[s];
    if(DP[s+2][e]==-1)
        DP[s+2][e] = GT(V,s+2,e,n);
    if(DP[s+1][e-1]==-1)
        DP[s+1][e-1] = GT(V,s+1,e-1,n);
    if(DP[s][e-2]==-1)
        DP[s][e-2]=GT(V,s,e-2,n);

    return max(V[s]+min(DP[s+2][e],DP[s+1][e-1]),V[e]+ min(DP[s+1][e-1],DP[s][e-2]));
}

int main()
{
ll t=1;
//cin >> t;
while(t--)
{
    ll n,W,i,j,k=2,l1,l2,m;
    ll r,c;
    cin >> n;
    ll ans=0;
    vector<ll> V(n);
    for(i=0;i<n;i++)
    {
        cin >> V[i];
        ans += V[i];
    }

    cout << (2LL*GT(V,0,n-1,n) - ans );
}
	return 0;
}
