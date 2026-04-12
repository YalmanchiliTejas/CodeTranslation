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

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz");
char s[10][10];
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
        cin.tie(0);
        cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>h>>w;
    rep(i,h)rep(j,w)cin>>s[i][j];
    ll lim=-1;
    rep(i,h){
        fl=false;
        rep(j,w){
            if(s[i][j]=='#'&&!fl){
                fl=true;
                if(lim>j){
                    Cout("Impossible");
                    return 0;
                }
            }
            if(s[i][j]=='#')lim=j;
        }
    }
    ll st=0;
    rep(i,h){
        fl=false;
        rrep(j,st,w){
            if(s[i][j]=='#'&&fl){
                Cout("Impossible");
                return 0;
            }
            if(s[i][j]=='.'&&!fl)fl=true,st=j;
            if(j==w-1&&!fl)st=w-1;
        }
    }
    Cout("Possible");
    return 0;
}
