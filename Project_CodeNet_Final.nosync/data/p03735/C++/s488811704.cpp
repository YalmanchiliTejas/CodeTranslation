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
#define tam 420000

#define offset 
const ll MOD= 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N;
ii A,B;
map<int,int> mapa;
int reverso[tam];
ll answer=2e18;
void change(ii &p ,ll valor)
{
    p.fi=min(p.fi,valor);
    p.se=max(p.se,valor);
}
void calc( ii &p1,ii &p2)
{
    //<<p1.fi<<" "<<p1.se<<" query  "<<p2.fi<<" "<<p2.se<<endl<<endl;
    answer=min(answer,(p1.se-p1.fi)*(p2.se-p2.fi));
}
int bit[tam];
vector<int> vect[tam];
int query(int pos)
{
    int tot=0;
    for(int i=pos;i>0;i-=i&-i)
    tot+=bit[i];
    return tot;
}
void update(int pos,int delta)
{
    for(int i=pos;i<tam;i+=i&-i)
    {
        bit[i]+=delta;
    }
}
int  main()
{
    B=A={1e9,-1e9};
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>N;
    int iz,der;
    vector<ii> lst;
    set<int> s;
    int minn=1e9;
    forr(i,0,N)
    {
        cin>>iz>>der;
        if (iz==der)
            change(A,iz),change(B,der);
        else
        {
            minn=min(minn,iz);
            minn=min(minn,der);
            s.insert(iz);
            s.insert(der);
            lst.pb({min(iz,der),max(iz,der)});
        }
    }   

    ii pA,pB;
    pA=A;pB=B; 
    for(auto par:lst)
    {
        change(pA,par.fi);
        change(pB,par.se);
    }
    calc(pA,pB);

    int cnt=1;
    for(auto num:s)
    {
        //<<num<<" mapeado "<<cnt<<endl;
        reverso[cnt]=num;
        mapa[num]=cnt++;
    }
    //<<endl;
    for(auto par:lst)
    {
        iz=mapa[par.fi];
        der=mapa[par.se];
        update(iz,1);
        vect[iz].pb(der);
    }
    int n=lst.size();
    for(auto num:s)
    {
        //<<num<<":\n";
        pA=A,pB=B;
        
        auto ite=s.end();ite--;
        change(pA,*ite);
        change(pA,*s.begin());

        int iz=1,der=cnt,mid;
        while(iz+1<der){
            mid=(iz+der)/2;
            if (query(mid)==n)
                der=mid;
            else
                iz=mid;
        }
        
        if (query(iz)==n)
            der=iz;
        //<<der<<" "<<query(der)<<endl;
        if (query(der)==n)
        {
            change(pB,num);
            change(pB,reverso[der]);
            calc(pA,pB);
        }
        int anum=mapa[num];
        int mivalor=query(anum)-query(anum-1);
        update(anum,-mivalor);
        forr(i,0,vect[anum].size())
        {
            update(vect[anum][i],1);
        }
    }
    cout<<answer<<endl;
}
// PLUS ULTRA!
