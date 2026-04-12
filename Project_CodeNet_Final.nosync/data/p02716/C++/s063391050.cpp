#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define fi first
#define sd second
#define lson (nd<<1)
#define rson (nd+nd+1)
#define PB push_back
#define mid (l+r>>1)
#define MP make_pair
#define SZ(x) (int)x.size()

using namespace std;

typedef long long LL;

typedef vector<int> VI;

typedef pair<int,int> PII;

inline LL read(){
    LL res=0, f=1;char ch=getchar();
    while(ch<'0'|ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}

const int MAXN = 200'005;

const int MOD = 1000000007;

const LL inf = (LL)1e18;

void addmod(int& a, int b){a+=b;if(a>=MOD)a-=MOD;}
int mulmod(int a, int b){return 1ll*a*b%MOD;}

template<typename T>
void chmin(T a, T b){if(a>b)a=b;}

template<typename T>
void chmax(T a, T b){if(b>a)a=b;}

LL a[MAXN], n;
map<int,long long> H[MAXN];

LL dfs(int idx, int cnt){
    if(idx>=n+1){
        if(cnt==n/2)return 0;
        else return -inf;
    }

    if(H[idx].count(cnt))return H[idx][cnt];

    if((cnt+(n-idx+2)/2)<n/2)return -inf;

    return H[idx][cnt]=max(dfs(idx+1,cnt),dfs(idx+2,cnt+1)+a[idx]);
}

int main(){
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();

    cout<<dfs(1,0);

    return 0;
}
