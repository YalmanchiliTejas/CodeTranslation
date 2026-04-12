#include <bits/stdc++.h>
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ALL(V) V.begin(),V.end()
#define f1(a,b) for(int a=1;a<=b;a++)
#define f0(a,b) for(int a=0;a<b;a++)
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
using namespace std;
const LL N=1e6+69, base=1024*1024, mod=1e9+7,ma=1e15;
priority_queue <pll> q;
LL n,m,po,ko,a,b,c,odl[N][2],odw[N][2],o,wynik;
LL dp[N][2];
vector <int> vek;
vector <pll> G[N];
pair<LL,pll> kra[N];
void dij(int,int);
int32_t main(void) {
    boost;
    cin>>n>>m;
    cin>>po>>ko;
    f1(i,m) {
        cin>>a>>b>>c;
        G[a].PB(MP(b,i));
        G[b].PB(MP(a,i));
        kra[i]=MP(c,MP(a,b));
    }
    dij(po,0);
    o=odl[ko][0];
    dij(ko,1);
    //cout<<o<<endl;
    //f1(i,n) cout<<dp[i][1]<<" ";
    //return 0;
    wynik=dp[ko][0];
    wynik*=wynik;
    wynik%=mod;
    f1(i,n) {
        if(o%2==1) continue;
        if(odl[i][0]==odl[i][1]&&odl[i][0]==o/2) {
            LL nwm=dp[i][0]*dp[i][1];
            nwm%=mod;
            nwm*=nwm;
            nwm%=mod;
            //cout<<dp[i][0]*dp[i][1]<<endl;
            wynik-=nwm;
            if(wynik<0) wynik+=mod;
            wynik%=mod;
        }
    }
    sort(ALL(vek));
    vek.resize(distance(vek.begin(),unique(ALL(vek))));
    f0(i,vek.size()) {
        int nr=vek[i];
        a=kra[nr].s.f;
        b=kra[nr].s.s;
        //cout<<"nisjdibnkjfd "<<a<<" "<<b<<endl;
        LL nwm=0;
        if(odl[a][0]<o/2&&odl[b][0]>o/2) nwm=dp[a][0]*dp[b][1];//, cout<<a<<" fddf "<<b<<endl;
        if(odl[b][0]<o/2&&odl[a][0]>o/2) nwm=dp[b][0]*dp[a][1];//, cout<<a<<" wfre "<<b<<endl;
        nwm%=mod;
        nwm*=nwm;
        nwm%=mod;
        wynik-=nwm;
        if(wynik<0) wynik+=mod;
        wynik%=mod;
    }
    cout<<wynik<<endl;
}
void dij(int v,int nr) {
    f1(i,n) odl[i][nr]=ma;
    odl[v][nr]=0;
    dp[v][nr]=1;
    q.push(MP(0,v));
    while(!q.empty()) {
        v=q.top().s;
        q.pop();
        if(odw[v][nr]==1) continue;
        odw[v][nr]=1;
        f0(i,G[v].size()) {
            int w=G[v][i].f;
            LL dod=kra[G[v][i].s].f;
            if(odl[w][nr]>odl[v][nr]+dod) {
                dp[w][nr]=dp[v][nr];
                odl[w][nr]=odl[v][nr]+dod;
                if(nr==1&&odl[w][1]+odl[w][0]==o) vek.PB(G[v][i].s);
                //if(nr==1&&G[v][i].s==8) cout<<"jan pawel "<<odl[w][1]<<" "<<odl[w][0]<<endl;
                q.push(MP(-odl[w][nr],w));
            }
            else if(odl[w][nr]==odl[v][nr]+dod) {
                if(nr==1&&odl[w][1]+odl[w][0]==o) vek.PB(G[v][i].s);
                //if(nr==1&&G[v][i].s==8) cout<<"jan pawel "<<odl[w][1]<<" "<<odl[w][0]<<endl;
                dp[w][nr]+=dp[v][nr];
                dp[w][nr]%=mod;
            }
        }
    }
}