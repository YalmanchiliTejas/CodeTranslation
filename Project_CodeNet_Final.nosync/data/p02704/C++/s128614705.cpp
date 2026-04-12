#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long   ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<ii, ll>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9;
const double PI = acos(-1);
#define tam 2000
#define offset 
const ll MOD= 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll fils[tam],cols[tam];
unsigned long long valfil[tam],valcol[tam];
ll vfil[tam],vcol[tam];
ll amat[tam][tam];
unsigned long long fmat[tam][tam];
ll n;
bool invalid;
void change(ll y0,ll x0,ll dy,ll dx,ll valor)
{
    while(y0<n && x0<n)
    {
        if (amat[y0][x0]!=-1 && amat[y0][x0]!=valor)
            invalid=1;
        amat[y0][x0]=valor;
        y0+=dy;
        x0+=dx;
    }
}
void trygreedy()
{
    forr(i,0,n)
    {
        if (cols[i]!=-1)
        {
            forr(y,0,n)
            {
                if (amat[y][i]==-1 && fils[y]==-1)
                {
                    amat[y][i]=cols[i];
                    cols[i]=-1;
                    break;
                }
                if (amat[y][i]==cols[i])
                {
                    cols[i]=-1;
                    break;
                }
            }
        }
        if (fils[i]!=-1)
        {
            forr(x,0,n)
            {
                if (amat[i][x]==-1 && cols[x]==-1)
                {
                    amat[i][x]=fils[i];
                    fils[i]=-1;
                    break;
                }
                if (amat[i][x]==fils[i])
                {
                    fils[i]=-1;
                    break;
                }
            }
        }
    }
}

ll bituniv;
void transform()
{
    
    forr(i,0,n)
    {
        forr(j,0,n)
        {
            if (amat[i][j]==-1)amat[i][j]=0;
            fmat[i][j]+=(amat[i][j]*(1LL<<bituniv));
            
        }
        
    }

}

ll  FILS[tam],COLS[tam];
void gotry()
{
    forr(i,0,n)
        fils[i]=FILS[i],cols[i]=COLS[i];
    memset(amat,-1,sizeof amat);
    forr(i,0,n)
    {
        if (cols[i]==0 && vcol[i]==1)
        {
            change(0,i,1,0,1);
            cols[i]=-1;
        }
        if (cols[i]==1 && vcol[i]==0)
        {
            change(0,i,1,0,0);
            cols[i]=-1;
        }
        if (fils[i]==0 && vfil[i]==1)
        {
            change(i,0,0,1,1);
            fils[i]=-1;
        }
        if (fils[i]==1 && vfil[i]==0)
        {
            change(i,0,0,1,0);
            fils[i]=-1;
        }
    }
    

    forr(tipo,0,2)
    {
        ll x,y;
        x=y=-1;
        forr(i,0,n)
        {
            if (cols[i]==tipo)
                x=i;
            if (fils[i]==tipo)
                y=i;
        }
        if (x!=-1 && y!=-1)
        {
            amat[y][x]=tipo;
            cols[x]=-1;
            fils[y]=-1;
            break;
        }
    }
    
    trygreedy();
    trygreedy();
    trygreedy();
    vector<ii> vvfil,vvcol;
    forr(i,0,n)
    {
        if (fils[i]!=-1)
            vvfil.pb({i,fils[i]});
        if (cols[i]!=-1)
            vvcol.pb({i,cols[i]});
    }
    
    if (vvfil.empty() && vvcol.empty())
    {
        transform();
        return;
    }

    
    ll N=vvfil.size(),M=vvcol.size();
    if (vvfil.empty() || vvcol.empty()|| N==1|| M==1)
    {
        invalid=1;
        return;
    }
    
    ll y0=vvfil[0].fi,tipo1=vvfil[0].se; 
    ll x0=vvcol[0].fi,tipo2=vvcol[0].se;
    amat[y0][x0]=tipo1;
    fils[y0]=-1;
    
    y0=vvfil[1].fi;
    amat[y0][x0]=tipo2;
    cols[x0]=-1;
    
    trygreedy();
    trygreedy();
    forr(i,0,n)
    {
        assert(fils[i]==-1);
        assert(cols[i]==-1);
    }
    transform();
        
}
int  main()
{
    
    cin>>n;
    forr(i,0,n)
    {
        cin>>FILS[i];
    }
    forr(i,0,n)
    {
        cin>>COLS[i];
    }
    forr(i,0,n)
    {
        cin>>valfil[i];
    }
    forr(i,0,n)
    {
        cin>>valcol[i];
    }

    forr(bit,0,64)
    {
        forr(j,0,n){
            vfil[j]=(valfil[j]&(1ULL<<bit))!=0;
            
        }
        
        forr(j,0,n){
            vcol[j]=(valcol[j]&(1ULL<<bit))!=0;
            
        }

        bituniv=bit;
        gotry();
    }
    if (invalid)
    {
        cout<<"-1\n";
        return 0;
    }
    forr(i,0,n)
    {
        forr(j,0,n)
        cout<<fmat[i][j]<<' ';
        cout<<endl;
    }
}
// PLUS ULTRA!
    