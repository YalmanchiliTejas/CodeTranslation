#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 

ll n,cnt,ans,a,b,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
char c[10][10];
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
        cin.tie(0);
        cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>h>>w;
    rep(i,h)rep(j,w)cin>>c[i][j];
    ll lim=-1;
    rep(i,h){
        tmp=LINF;
        tmpp=-1;
        rep(j,w){
            if(c[i][j]=='#'){
                tmp=min(tmp,(ll)j);
                tmpp=max(tmpp,(ll)j);
            }
        }
        if(tmpp==-1||lim>tmp){
            Cout("Impossible");
            return 0;
        }
        lim=tmpp;
    }
    Cout("Possible");
    return 0;
}
