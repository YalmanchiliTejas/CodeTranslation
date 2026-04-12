#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))
#define ALL(v) (v).begin(),(v).end()

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

const ll MOD = 1000000007ll;

int n;
int a[125252];

const int N = 1<<17;
int dat[2*N];
void qset(int i, int x){
    i += N-1;
    dat[i] = x;
    while(i>0){
        i=(i-1)/2;
        dat[i] = max(dat[2*i+1],dat[2*i+2]);
    }
}
int qmax(int l, int r, int a, int b, int k){
    if(r<=a || b<=l)return -1<<30;
    if(l<=a && b<=r)return dat[k];
    int m = (a+b)/2;
    return max(qmax(l,r,a,m,2*k+1),qmax(l,r,m,b,2*k+2));
}

int main(){
    scanf("%d",&n);
    REP(i,n)scanf("%d",a+i);
    int ans = 0;
    fill(dat,dat+2*N,-1<<30);
    REP(i,n)qset(i,a[i]);
    set<int> ids;
    REP(i,n)ids.insert(i);
    while(ids.size()){
        ans++;
        int c = *ids.begin(); ids.erase(c);
        qset(c,-1<<30);
        while(true){
            int l = c+1;
            int ok = n+1;
            int ng = l;
            while(abs(ok-ng)>1){
                int x = (ok+ng)/2;
                (qmax(l,x,0,N,0)>a[c] ? ok : ng) = x;
            }
            if(ok==n+1)break;
            c = ok-1;
            ids.erase(c); qset(c,-1<<30);
        }
    }
    printf("%d\n",ans);
    return 0;
}
