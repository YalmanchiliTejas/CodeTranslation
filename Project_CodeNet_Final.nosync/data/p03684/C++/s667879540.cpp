#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;i++)
#define REP1(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define RREP1(i,a,b) for(int i=a;i>b;i--)
#define RREP2(i,a,b) for(int i=a;i>=b;i--)
#define SREP(i,x) for(auto i:x)
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define MSF(x) memset((x),127,sizeof(x))
#define pb push_back
#define LE(x) (int)((x).size())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
#define debug 0
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
inline ll rit(){
    ll f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
void init(){
}
const int Z = 100005;
int mk[Z];
tuple<int,int,int> tx[Z],ty[Z];
int n;
int x[Z],y[Z],belongx[Z],belongy[Z];
priority_queue<PII,vector<PII>,greater<PII> > pq;
int srt(tuple<int,int,int> ta,tuple<int,int,int> tb){
    return get<0>(ta) < get<0>(tb);
}
int srt2(tuple<int,int,int> ta,tuple<int,int,int> tb){
    return get<1>(ta) < get<1>(tb);
}
void read(){
    RI(n);
    REP(i,n){
        RII(x[i],y[i]);
        ty[i] = tx[i] = mt(x[i],y[i],i);
    }
    sort(tx,tx+n,srt);
    sort(ty,ty+n,srt2);
    REP(i,n){
        belongx[get<2>(tx[i])] = i;
        belongy[get<2>(ty[i])] = i;
    }
}
void solve(){
    PII f;
    int tar;
    ll ans;
    ans=  0;
    pq.push(mp(0,0));
    while(!pq.empty()){
        f = pq.top();
        pq.pop();
        if(mk[f.Y]) continue;
        ans+=f.X;
        mk[f.Y] = 1;
        if(belongx[f.Y] > 0 ){
            tar = get<2>(tx[belongx[f.Y]-1]);
            pq.push(mp(abs(x[f.Y] - x[tar]),tar));
        }
        if(belongx[f.Y] < n-1){
            tar = get<2>(tx[belongx[f.Y]+1]);
            pq.push(mp(abs(x[f.Y] - x[tar]),tar));
        }
        if(belongy[f.Y] > 0 ){
            tar = get<2>(ty[belongy[f.Y]-1]);
            pq.push(mp(abs(y[f.Y] - y[tar]),tar));
        }
        if(belongy[f.Y] < n-1){
            tar = get<2>(ty[belongy[f.Y]+1]);
            pq.push(mp(abs(y[f.Y] - y[tar]),tar));
        }
    }
    cout<<ans<<endl;

}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        // while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}