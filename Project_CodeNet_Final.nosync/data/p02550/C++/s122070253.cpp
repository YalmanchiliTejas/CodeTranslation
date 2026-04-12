#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a-1;i>=b;i--)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define SP(x) setprecision(x)
#define sz(x) (int)x.size()
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define endl '\n'
#define int long long

signed main()
{
    

    int n,x,m;
    cin>>n>>x>>m;

    vector<int> cycle;
    int sum=0;

    int vis[m+1];
    mem(vis,0);

    while(!vis[x])
    {
        cycle.pb(x);
        sum+=x;
        vis[x]=1;
        x=x*x%m;
    }

    int before=0;
    sum=0;
    int ans=0;
    while(cycle[before]!=x) before++;


    if(n<=before)
    {
        ffor(i,0,n) ans+=cycle[i];
        cout<<ans;
        return 0;
    }
    else
    {
        ffor(i,0,before) ans+=cycle[i];
        n-=before;
        ffor(i,before,sz(cycle)) sum+=cycle[i];
    }

   // cout<<before<<" "<<sum<<endl;

    int len=sz(cycle)-before;

    ans+=sum*(n/len);
    ffor(i,before,before+(n%len)) ans+=cycle[i];
    cout<<ans;
    
    return 0;
}

