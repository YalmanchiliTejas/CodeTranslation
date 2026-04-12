
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
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
typedef pair<int, int>  ii;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9;
const double PI = acos(-1);
#define offset 
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 530000
map<int,int> mapax,mapay;
int valorx[tam];
int valory[tam];
set<int> vnums[tam];
int arrpa[tam];
int cnt[tam];
int findpa(int num)
{
    if (arrpa[num]==num)
        return num;
    return arrpa[num]=findpa(arrpa[num]);
}
void join(int x,int y)
{
    int pa1=findpa(x);
    int pa2=findpa(y);
    if (pa1==pa2)
        return;
    
    if (cnt[pa1]>cnt[pa2])
        swap(x,y),swap(pa1,pa2);
    for (auto num:vnums[pa1])
    {
        vnums[pa2].insert(num);
    }
    cnt[pa2]+=cnt[pa1];
    arrpa[pa1]=pa2;
}
bool tryjoin(int num1,int num2)
{
    return (findpa(num1)!=findpa(num2));
}
int  main()
{  
    forr(i,0,tam){
        arrpa[i]=i;
        cnt[i]=1;
        vnums[i].insert(i);
    }
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<ii> lst;
    set<int> sx,sy;
    int x,y;
    forr(i,0,n)
    {
        cin>>x>>y;
        lst.pb({x,y});
        sx.insert(x);
        sy.insert(y);
    }
    vector<int> numeros;
    set<int> cordx,cordy;

    int cunivx,cunivy;
    cunivx=1;cunivy=3e5;
    for(auto num:sx)
    {
        numeros.pb(cunivx);
        cordx.insert(cunivx);
        valorx[cunivx]=num;
        mapax[num]=cunivx++;
    }
    for(auto num:sy)
    {
        numeros.pb(cunivy);
        cordy.insert(cunivy);
        valory[cunivy]=num;
        mapay[num]=cunivy++;
    }
    for(auto par:lst)
    {
        x=mapax[par.fi];
        y=mapay[par.se];
        //cout<<x<<' '<<y<<endl;
        join(x,y);
    }
    set<ii> valores;
    for(auto num:numeros)
    {
        if (findpa(num)==num)
        {
            /*cout<<num<<" lest begin\n";
            for(auto extra:vnums[num])
                cout<<extra<<' ';
            cout<<endl;*/

            valores.insert(mp(cnt[num],num));
        }
    }
    ll total=0;
    while(valores.size()>1)
    {
        auto num=(*valores.begin()).se;
        ii unir={INF,num};
        for(auto cord:vnums[num])
        {
            set<int>::iterator itenext;
            //cout<<cord<<" "<<unir.fi<<"   ";
            if (cord>=3e5)
            {
                y=cord;
                itenext=cordy.upper_bound(y);
                if (itenext!=cordy.end())
                {
                    if (tryjoin(*itenext,num))
                        unir=min(mp(abs(valory[y]-valory[*itenext]),*itenext),unir);
                }
                itenext--;
                if (itenext!=cordy.begin())
                {
                    itenext--;
                    if (tryjoin(*itenext,num))
                        unir=min(mp(abs(valory[y]-valory[*itenext]),*itenext),unir);
                }
            }
            else
            {
                x=cord;
                itenext=cordx.upper_bound(x);
                if (itenext!=cordx.end())
                {
                    if (tryjoin(*itenext,num))
                        unir=min(mp(abs(valorx[x]-valorx[*itenext]),*itenext),unir);
                }
                itenext--;
                if (itenext!=cordx.begin())
                {
                    itenext--;
                    if (tryjoin(*itenext,num))
                        unir=min(mp(abs(valorx[x]-valorx[*itenext]),*itenext),unir);
                }
            }
        }
        //cout<<endl;
        //cout<<"finaliza\n";
        if (unir.fi!=INF)
        {
            total+=unir.fi;
            int num2=unir.se;
            assert(tryjoin(num,num2));
            
            valores.erase({cnt[findpa(num2)],findpa(num2)});
            valores.erase(valores.begin());
            join(num,num2);
            num=findpa(num);

            valores.insert({cnt[num],num});
            //cout<<valores.size()<<endl;
        }
        else
        {
            cout<<valores.size()<<endl;
            assert(false);
            break;
        }
    }
    cout<<total<<endl;

}   
// PLUS ULTRA!!