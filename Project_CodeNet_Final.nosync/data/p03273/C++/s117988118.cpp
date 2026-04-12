//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debug cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e7+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
void solve()
{
    ll n,m;
    cin>>n>>m;
    string s[n];
    vector<bool>r(n,0),c(m,0);
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {bool flag=0;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                flag=1;break;
            }
        }
        if(!flag)
            r[i]=1;
    }
    for(int i=0;i<m;i++)
    {
        bool flag=0;
        for(int j=0;j<n;j++)
        {
            if(s[j][i]=='#')
            {
                flag=1;break;
            }
        }
        if(!flag)
            c[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(!r[i])
        {
            for(int j=0;j<m;j++)
            {
                if(!c[j])
                    cout<<s[i][j];
            }
            cout<<endl;
        }
    }
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;for(int te=1;te<=t;te++)
    {
        solve();
    }
    return 0;
}