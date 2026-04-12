#include <bits/stdc++.h>
#define pb push_back
#define tam 320
#define se second
#define fi first
#define pitem item*
#define forr(i,p,n) for(int i=p;i<n;i++)
using namespace std;
typedef long long ll;
const ll MOD=1000000007 ;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
typedef pair<int,int> ii;
typedef vector<vector<int> > vvi;
typedef  double lld;
bool grafo[tam][tam];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(grafo,0,sizeof grafo);
    int iz,der;
    forr(i,0,m)
    {
        cin>>iz>>der;
        grafo[iz][der]=1;
        grafo[der][iz]=1;
    }
    vector<int> v;
    forr(i,1,n+1)
    {
        v.pb(i);
    }
    int tot=0;
    do
    {
        bool nop=false;
        if (v[0]!=1)
            continue;
        forr(i,0,v.size()-1)
        {
            if (grafo[v[i]][v[i+1]]==0)
                nop=1;
        }
        if (nop==0)
            tot++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<tot<<endl;
}