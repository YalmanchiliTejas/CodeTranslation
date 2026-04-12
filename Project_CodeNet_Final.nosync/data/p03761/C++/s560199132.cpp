#include <bits/stdc++.h>
#define pb push_back
#define tam 1204
#define offset 320000
#define se second
#define fi first
#define pitem item*
#define ptr tre*
#define forr(i,p,n) for(int i=p;i<n;i++)
using namespace std;
typedef long long ll;
const ll MOD=1000000009 ;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int mapa[tam][tam];
int main()
{
    int n;
    cin>>n;
    string txt;
    memset(mapa,0,sizeof mapa);
    forr(i,0,n)
    {
        cin>>txt;
        forr(j,0,txt.size())
        {
            mapa[i][txt[j]]++;
        }
    }
    forr(i,'a','z'+1)
    {
        int minn=1e9;
        forr(j,0,n)
        {
            minn=min(minn,mapa[j][i]);
        }
        forr(j,0,minn)
        {
            cout<<char(i);
        }
    }
}