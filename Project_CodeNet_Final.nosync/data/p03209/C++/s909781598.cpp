#include <bits/stdc++.h>
typedef long long ll;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,sou[ohara],niku[ohara];
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

ll dfs(ll le,ll pa){
    if(pa==0)return 0;
    else if(le==0)return 1;
    else if(pa<=sou[le-1]+1)return dfs(le-1,pa-1);
    else if(pa==sou[le-1]+2)return niku[le-1]+1;
    else if(pa<=sou[le-1]*2+2)return niku[le-1]+1+dfs(le-1,pa-2-sou[le-1]);
    else return niku[le-1]*2+1;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>n>>x;
    sou[0]=1;
    rrep(i,1,100){
        sou[i]=sou[i-1]*2+3;
    }
    niku[0]=1;
    rrep(i,1,100){
        niku[i]=2*niku[i-1]+1;
    }
    Cout(dfs(n,x));
    return 0;
}
