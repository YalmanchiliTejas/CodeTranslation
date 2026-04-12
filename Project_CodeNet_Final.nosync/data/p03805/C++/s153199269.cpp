#include <bits/stdc++.h>
typedef long long ll;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a,b,c,d,e,f,tmp,tmpp,m,h,w,x,y,sum,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s[ohara],co;
bool fl;
struct edge{int to,cost;};
vector<ll> graph[ohara];
map<pair<ll,ll>,ll> mp;

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    rep(i,m){
        cin>>a>>b;
        a--;b--;
        mp[{a,b}]=1;
        mp[{b,a}]=1;
    }
    vector<ll> p(n);
    rep(i,n)p[i]=i;
    do{
        a=0;
        if(p[0]!=0)continue;
        rep(i,n-1){
            if(mp[{p[i],p[i+1]}]==0){
                a=1;
                break;
            }
        }
        if(a==0)ans++;
    }while(next_permutation(all(p)));
    Cout(ans);
    return 0;
}
