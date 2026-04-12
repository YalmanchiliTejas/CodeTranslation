#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pii pair<int,pi>
#define pl pair<ll,ll>
#define pll pair<ll,pl>
#define debug cout<<"debugging"<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int I_LIMIT = 999999999;
ll L_LIMIT = 19999999999999999;
ll mod = 998244353;

void solve()
{
    ll n,x,m,i,ans=0,p,s,c,sum1,sum2,k;
    cin>>n>>x>>m;
    ll A[m];
    for(i=0;i<m;i++)
        A[i] = (i*i)%m;
    
    bool visited[m];
    memset(visited,false,sizeof(visited));
    
    p = x;
    while(visited[p]==false)
    {
        visited[p] = true;
        p = A[p];
    }

    s = A[p];
    c = 1;
    sum1 = p;
    while(s!=p)
    {
        sum1 += s;
        s = A[s];
        c++;
    }

    s = A[x];
    sum2 = x;
    n--;
    while(n>0 && s!=p)
    {
        n--;
        sum2 += s;
        s = A[s];
    }

    if(n==0)
    {
        cout<<sum2<<"\n";
        return;
    }
    
    k = n/c;
    ans = sum2 + k*sum1;
    
    n = n%c;

    if(n==0)
    {
        cout<<ans<<"\n";
        return;
    }
    s = A[p];
    sum1 = p;
    n--;
    while(n>0)
    {
        n--;
        sum1 += s;
        s = A[s];
    }

    ans += sum1;
    cout<<ans<<"\n";
}
int main()
{
    IOS;
    solve();
}
