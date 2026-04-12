#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
viii p,q;
viii edj;

struct DSU
{
    int n,x;
    vi p,r,sz;
    DSU(int N)
    {
        n=N;
        x=N-1;
        sz.assign(N,1);
        p.assign(N,0);
        r.assign(N,1);
        for(int i=0;i<N;i++)
            p[i]=i;
    }
    int findset(int i)
    {
        return (p[i]==i)?i:(p[i]=findset(p[i]));
    }
    bool issameset(int i,int j)
    {
        return findset(i)==findset(j);
    }
    void unionset(int i,int j)
    {
        int p1=findset(i);
        int p2=findset(j);
        if(p1!=p2)
        {
            x--;
            if(r[p1]>=r[p2])
            {
                p[p2]=p1;
                sz[p1]+=sz[p2];
                if(r[p1]==r[p2])
                    r[p1]++;
            }
            else
            {
                p[p1]=p2;
                sz[p2]+=sz[p1];
            }
        }
    }
    void disp()
    {
        for(int i=0;i<n;i++)
            cout<<p[i]<<' ';
        cout<<endl;
    }

    int getsize(int i){
        return sz[findset(i)];
    }
    int noofdisjointsets(){
        return x;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        p.pb(mc(x,y,i));
        q.pb(mc(y,x,i));
    }
    sort(all(p));
    sort(all(q));
    for(int i=0;i<n-1;i++){
        edj.pb(mc(p[i+1].F.F-p[i].F.F,p[i+1].S,p[i].S));
        edj.pb(mc(q[i+1].F.F-q[i].F.F,q[i+1].S,q[i].S));
    }

    DSU foo(n);

    sort(all(edj));
    ll cost = 0;
    for(int i=0;(i<edj.size())&&(foo.noofdisjointsets());i++){
        x = edj[i].F.S;
        y = edj[i].S;
        if(!foo.issameset(x,y)){
            foo.unionset(x,y);
            cost+=edj[i].F.F;
        }
    }
    cout<<cost;
    




    return 0;
}