#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
const int MAX =510000;

ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
    ll g;g=gcd(a,b);
    return a*b/g;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H=in();
    int W=in();
    char saisyo[H][W];
    bool h[H]={};
    bool w[W]={};
    string s;
    bool flg;
    REP(i,H){
        cin>>s;
        flg=true;
        REP(j,W){
            saisyo[i][j]=s[j];
            if(s[j]=='#')flg=false;
        }
        if(flg){
            h[i]=true;
        }
    }
    REP(i,W){
        
        flg=true;
        REP(j,H){
            if(saisyo[j][i]=='#'){
                flg=false;
            }
        }
        if(flg)w[i]=true;
    }
    REP(i,H){
        if(h[i]){
            //debug(i);
            continue;
        }
        REP(j,W){
            if(w[j]){
                //debug(j);
                continue;
            }
            cout<<saisyo[i][j];
        }
        cout<<endl;
    }
    return 0;
}